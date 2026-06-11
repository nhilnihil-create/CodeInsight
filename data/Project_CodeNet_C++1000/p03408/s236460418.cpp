#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    map<string,int>mp;
    int n,m,ans=0;
    string s,t;
    
    cin >> n;
    rep(i,n){
        cin >> s;
        mp[s]++;
    }
    
    cin >> m;
    rep(i,m){
        cin >> t;
        mp[t]--;
    }
    
    for(auto i=mp.begin();i!=mp.end();i++)ans=max(ans,i->second);
    
    cout << ans;
    
	return 0;
}