#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define PRECISION 15
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    double ans = 0;
    for(int i=1; i<=n; i++){
        double tmp = 1.0 / n;
        double cmp = i;
        while(cmp < k){
            cmp *= 2;
            tmp /= 2;
        }
        ans += tmp;
    }
    cout << fixed << setprecision(PRECISION) << ans << endl;
    return 0;
}
