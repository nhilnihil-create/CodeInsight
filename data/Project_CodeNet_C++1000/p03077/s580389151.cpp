#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll (i)=0;(i)<(ll) (n);(i)++)
int main(void){
    ll i=0,j,p,h[1000010],k,n,a,b,c,d,e,m;
    cin >> n >> a >> b >> c >> d >> e;
    m=min({a,b,c,d,e});
    if(m<n)
    {
        if(n%m!=0)
        {
            m=n/m+5;
        }
        else
        {
            m=n/m+4;
        }
    }
    else
    {
        cout << '5' << endl;
        return 0;
    }
    cout << m << endl;
    
    return 0;

}
