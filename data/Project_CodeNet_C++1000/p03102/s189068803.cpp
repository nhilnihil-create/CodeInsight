#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll) (n);i++)
int main(void){
    ll p=0,b[10010],n,m,c,a[1000][1000],co=0;
    cin >> n >> m >> c;
    rep(i,m)
    {
        cin >> b[i];
    }
    rep(i,n)
    {
        rep(j,m)
        {
            cin >> a[i][j];
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            p+=a[i][j]*b[j];
        }
        if(p+c>0)
        {
            co++;
        }
        p=0;
    }
    cout << co << endl;
    return 0;

}
