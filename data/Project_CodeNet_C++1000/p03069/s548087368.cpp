#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n-2; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    ll n,ans=INF;
    string s;
    cin >> n >> s;
    int k = s.size();
    
    vector<ll>lb(n,0);
    vector<ll>rw(n,0);
    
    rep2(i,1,n){
        if(s[i-1]=='#')lb[i]=lb[i-1]+1;
        else lb[i]=lb[i-1];
    }
    for(int i=n-2;i>=0;i--){
        if(s[i+1]=='.')rw[i]=rw[i+1]+1;
        else rw[i]=rw[i+1];
    }
    
    rep(i,n)ans=min(ans,(rw[i]+lb[i]));
    
    cout << ans;
    
	return 0;
}