#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 100000
#define mod 1000000007
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col;
string s;
ll dp[3006][3006];//dp[i][j] = number of permutations of i+1 length using first i+1 numbers
ll sum[3006][3006];
//with j as last character
void solve()
{
  int ans=0;
	cin>>n>>s;
  dp[1][1]=1;
	for(int i=2;i<=n;i++){
		if(s[i-2]=='<'){
			for(int j=1;j<=i;j++){
				dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%mod;
			}
		}
		else{
			dp[i][i]=0;
			for(int j=i-1;j>=1;j--){
				dp[i][j]=(dp[i-1][j]+dp[i][j+1])%mod;
			}
		}
	}
  for(int i=1;i<=n;i++){
		ans=(ans+dp[n][i])%mod;
	}
	cout<<ans<<endl;

}



void test()
{
  int t;
  //scanf("%d",&t);
  t = 1;
  for(int test=1;test<=t;test++)
  {
    solve();
  }
}
int main()
{
  test();
  return 0;
}
