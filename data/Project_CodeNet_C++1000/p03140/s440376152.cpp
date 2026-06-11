#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n;cin>>n;
    string s,t,u;cin>>s>>t>>u;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        set<char> st={s[i],t[i],u[i]};
        ans+=st.size()-1;
    }
    cout<<ans;
}