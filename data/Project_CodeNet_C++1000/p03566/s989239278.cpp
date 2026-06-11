#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<double> t(N+2);
    for (int i = 1; i <= N; i++){
        double n;
        cin >> n;
        t[i] = t[i-1] + 2*n;
    }
    t[N+1] = t[N];

    vector<double> v(N+2);
    for (int i = 1; i <= N; i++){
        cin >> v[i];
    }
    
    vector<double> s(t[N], 100000);
    for (int i = 0; i <= t[N]; i++) {
        for (int j = 0; j <= N+1; j++) {
            double f;
            if(i >= t[j]) {
                f = v[j] + 0.5 * (i-t[j]);
            }
            else if(i >= t[j-1]) {
                f = v[j];
            }
            else {
                f = v[j] + 0.5 * (t[j-1] - i);
            }

            s[i] = min(s[i], f);
        }
    }

    double ans = 0;
    for(int i = 1; i <= t[N]; i++) {
        ans += 0.25 * (s[i] + s[i-1]);
    }
    
    printf("%.5lf", ans);
    return 0;
}