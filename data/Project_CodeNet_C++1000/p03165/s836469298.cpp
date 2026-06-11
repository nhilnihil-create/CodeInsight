#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s, t;

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> s >> t;
  vector<vi> dp(s.size()+1, vi(t.size()+1, 0));
  rep(i, 1, s.size()){
  	rep(j, 1, t.size()){
  		if(s[i-1]==t[j-1]){
  			dp[i][j]=1+dp[i-1][j-1];
  			// cout << s[i]<<endl;
  		}
  		else{
  			dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
  		}
  	}
  }
  int x=s.size(), y=t.size();
  int cnt=dp[x][y];
  string ans;
  while(cnt){
  	if(dp[x][y]>dp[x-1][y] && dp[x][y]>dp[x][y-1]){
  		ans+=s[x-1];
  		// cout << s[x] << endl; 
  		x--; y--; cnt--; 
  		
  	}
  	else if(dp[x][y]==dp[x-1][y]) x--;
  	else if(dp[x][y]==dp[x][y-1]) y--;
  }
  reverse(all(ans));
  cout << ans;
}