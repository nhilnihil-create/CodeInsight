#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n; cin>>n;
    vector<string> s(n);
    set<string> st;
    rep(i,n){
        cin>>s[i];
        st.insert(s[i]);
    }
    bool ok=true;
    if(st.size()!=n) ok=false;
    for(int i=1;i<n;i++){
        if(s[i][0]!=s[i-1][s[i-1].size()-1]) ok=false;
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}