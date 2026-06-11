#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    int n;cin>>n;
    string s;int ab=0,a=0,b=0,ans=0;
    REP(i,n){
        cin>>s;
        REP(i,s.size()-2){
            if(s[i]=='A'&&s[i+1]=='B')ans++;
        }
        if(s[0]=='B')b++;
        if(s[s.size()-1]=='A')a++;
        if(s[0]=='B'&&s[s.size()-1]=='A')ab++;
    }
    cout<<ans+min(a,b)+(a==b&&b==ab&&ab!=0?-1:0)<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}