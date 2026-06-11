#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fp(i,a,b) for(int i=a ; i<b ; i++)
#define fn(i,a,b) for(int i=a ; i>=b ; i--)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int M=3005;
const ll INF=1e15;
const int MOD=1e9+5;

int n;
double p[M],dp[M][M];

double DP(int i,int ts){
  if (i > n) return 1;
  if (ts*2 > n) return 0;
  if (dp[i][ts] != -1) return dp[i][ts];
  dp[i][ts] = p[i+1]*DP(i+1,ts) + (1-p[i+1])*DP(i+1,ts+1);
  return dp[i][ts];
}

int main(){

	fastio;
  cin >> n;
  fp(i,1,n+1) cin >> p[i];
  fp(i,0,n+1)
    fp(j,0,n+1) dp[i][j] = -1;
  cout << fixed << setprecision(10) << DP(0,0) << "\n";

	return 0;
}
