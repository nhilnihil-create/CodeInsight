#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long

int main(void)
{
    ll n,q;
    string str; 
    cin>>n>>q>>str;

    vector<ll> s(n+1,0);
    rep(i,n){
        if(i+1<n&&str[i]=='A'&&str[i+1]=='C') s[i+1]=s[i]+1;
        else s[i+1]=s[i];
    }

    rep(i,q){
        ll l,r; cin>>l>>r;
        l--; r--;
        cout<<s[r]-s[l]<<endl;
    }
    return 0;
}