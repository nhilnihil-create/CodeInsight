
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N=1e6+100;
const int inf=0x3f3f3f3f;

int n,m;

ll qpow(ll x,ll n)
{
    ll sum=1;
    while(n){
        if(n&1){
            sum=sum*x;
        }
        x*=x;
        n>>=1;
    }
    return sum;
}
void solve()
{
    ll a,b;
    cin>>a>>b;
    ll len=b-a+1;
    if(len==1) {
        cout<<a<<endl;
        return ;
    }
    ll l,r;
    if(a%2) l=a,a++,len--;
    else l=0;
    if(b%2) r=0;
    else r=b,b--,len--;
    if(len%4) {
        cout<<(l^r^1)<<endl;
    }
    else cout<<(l^r)<<endl;

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    solve();
    return 0;
}
