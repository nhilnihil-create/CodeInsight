#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vector<int>> vvi;
#define deb(x) cout << #x << " : " << x << endl
#define deb2(x , y) cout << #x << " : " << x << " , "<< #y << " : " << y << endl
#define debv(x) for(auto i=x.begin();i!=x.end();i++) cout<<*i<<' ';cout<<endl
#define debvv(x) for(auto j=x.begin();j!=x.end();j++) { for(auto i=(*j).begin();i!=(*j).end();i++) cout<<*i<<' ';cout<<endl;}cout<<endl
#define debp(x) for(auto i=x.begin();i!=x.end();i++) cout<<i->first<<':'<<i->second<<' ';cout<<endl
#define rsz(x,n) x.clear(); x.resize(n)
#define rrsz(x,a,n) x.clear(); x.resize(n,a)
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define wt while(true)
#define all(x) x.begin(),x.end()
#define pb push_back
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define INF (1e9 + 7)
#define endl '\n'

void solve() {
	string s,t,ans="";
	cin>>s>>t;
	int n=s.size(),m=t.size();
	vvi dp(n+1,vi(m+1,0));
	reps(i,1,n+1){
		reps(j,1,m+1){
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
    //debvv(dp);
  	int x=n,y=m;
  	while(x!=0 && y!=0){
  		if(dp[x-1][y]==dp[x][y]){
  			--x;
  		}
  		else if(dp[x][y-1]==dp[x][y]){
  			--y;
  		}
  		else{
  			ans=t[y-1]+ans;
          	x--;
          	y--;
  		}
  	}
  	cout<<ans;
}

int main() {
	csl;
	int testcase=1;
//	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		solve();
	}
	return 0;
}
