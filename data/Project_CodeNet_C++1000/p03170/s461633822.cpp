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

int n, a, k;
vi stones;
int dp[100001];

bool calc(int x){
	if(dp[x]!=-1) return dp[x];
	if(x==0) return dp[x]=0;
	bool ans=false;;
	trav(s, stones){
		if(x-s>=0){
			if(!(dp[x-s]=calc(x-s))){
				ans=true; break;
			}
		}
	}
	return dp[x]=ans;
}

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n >> k;
  rep(i, 1, n){
  	cin >> a;
  	stones.pb(a);
  }
  rep(i, 0, k) dp[i]=-1;
  cout << (calc(k)? "First" : "Second");
}