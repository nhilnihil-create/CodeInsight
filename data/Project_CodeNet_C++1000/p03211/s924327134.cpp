#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod=1e9+7;
// Not for Rating """"""""""I'm in Love with Experience :)""""""""""""""""""
void solve()
{
    string str;cin>>str;
    ll N=str.length();
    ll p=0,a=753,mn=1000;
    for(ll i=0;i<N-2;++i)
    {
        p=100*(str[i]-'0')+ 10*(str[i+1]-'0') + (str[i+2]-'0');
        //cout<<p<<'\n';
        mn=min(mn,abs(p-753));
    }
    cout<<mn;
}
int main(void)
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T=1;while(T--){solve();}return 0;
}/*Solved By:- RITIK AGARWAL*/