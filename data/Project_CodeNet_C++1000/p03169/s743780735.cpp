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

double n, a, x, y, z;
double dp[301][301][301];

double calc(int i, int j, int k){
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	if(i==0 && j==0 && k==j) return 0;
	double ans=1;
	int z = n-(i+j+k);
	if(i) ans+=(double)i/(double)n*(dp[i-1][j][k]=calc(i-1, j, k));
	if(j) ans+=(double)j/(double)n*(dp[i+1][j-1][k]=calc(i+1, j-1, k));
	if(k) ans+=(double)k/(double)n*(dp[i][j+1][k-1]=calc(i, j+1, k-1));
	ans*=(double)n/(double)(n-z);
	return dp[i][j][k]=ans;
}

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cout << setprecision(9) << fixed;
  x=0; y=0; z=0;
  cin >> n;
  rep(i, 1, n){
  	cin >> a;
  	if(a==1) x++;
  	else if(a==2) y++;
  	else z++;
  }
  rep(i, 0, n){
  	rep(j, 0, n){
  		rep(k, 0, n){
  			dp[i][j][k]=-1;
  		}
  	}
  }
  cout << calc(x, y, z);
}