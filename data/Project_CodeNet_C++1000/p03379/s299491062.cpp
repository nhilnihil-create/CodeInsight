#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<ll> x(N);
    vector<ll> x_sorted(N);
    rep(i, N) cin >> x[i];
    rep(i, N) x_sorted[i] = x[i];
    sort(x_sorted.begin(), x_sorted.end());
    ll line_num = x_sorted[N/2];
    rep(i, N){
        if(x[i] < line_num) cout << x_sorted[N/2] << endl;
        else cout << x_sorted[N/2-1] << endl;
    }
    return 0;
}