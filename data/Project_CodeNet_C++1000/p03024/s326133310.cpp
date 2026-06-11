#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    string s;cin>>s;
    ll n=s.size();
    ll ans = 15-n;
    for(ll i=0;i<n;i++)ans+=(s[i]=='o');
    cout<<(ans>=8?"YES\n":"NO\n");
}


