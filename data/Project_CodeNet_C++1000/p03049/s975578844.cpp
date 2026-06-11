#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n;cin>>n;
    ll a=0,b=0,c=0,ans=0;
    for(ll i=0;i<n;i++){
        string s;cin>>s;
        for(ll j=0;j<ll(s.size())-1;j++)if(s[j]=='A' && s[j+1]=='B')ans++;

        if(s[0]=='B' && s[s.size()-1ll]=='A')c++;
        else if(s[0]=='B')b++;
        else if(s[s.size()-1ll]=='A')a++;
    }

    if(a>0 && b>0)ans+=min(a,b) + c;
    else if(a>0)ans+=c;
    else if(b>0)ans+=c;
    else ans+=max(0ll,c-1);

    cout<<ans;
}



