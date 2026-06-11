#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=sz(s);
    
    int ans=n;
    rep(i,n-1){
        if(s[i]!=s[i+1]){
            ans=min(ans,max(i+1,n-1-i));
        }
    }
    cout<<ans<<endl;
}

