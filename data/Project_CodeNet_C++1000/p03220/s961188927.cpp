#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod=1e9+7;
// Not for Rating """"""""""I'm in Love with Experience :)""""""""""""""""""
void solve()
{
    ll N;cin>>N;
    double T,x,a;cin>>T>>x;
    double p=0.0;
    double mn=99999999999999.999999;
    for(ll i=1;i<=N;++i)
    {
        cin>>p;
        p=T -p*(0.006);
        p=abs(x-p);
        if(mn>p)
        {
            mn=p;
            a=i;
        }
    }
    cout<<a<<'\n';
}
int main(void)
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T=1;while(T--){solve();}return 0;
}/*Solved By:- RITIK AGARWAL*/