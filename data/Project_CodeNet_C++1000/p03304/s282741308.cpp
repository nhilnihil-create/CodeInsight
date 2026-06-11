#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    double n,m,d;
    cin >> n >> m >> d;
    double ans;
    if(abs(d) > 0.1){
        ans = 2*(n-d)/(n*n)*(m-1.0);
    }else{
        ans = (n-d)/(n*n)*(m-1.0);
    }
    
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}