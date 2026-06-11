#include<bits/stdc++.h>
#define fo(i,a,b) for(int i= a ; i < b ; ++i)
#define rep(i,n) fo(i,0,n)
#define pln(n) printf("%lld\n",n)
#define sll(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define dbg3(x,y,z) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) <<" , "<< #z <<": "<<(z)<<endl; }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define vll vector<long long>
#define vvi vector<vector<int>>
#define si set<int>
#define tr(c, it) \
for(decltype(c.begin()) it = c.begin(); it!= c.end(); it++)
#define pis pair<int,string>
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c),x) != c.end())
#define mod (int)(1e9 + 7) 

using namespace std;
int dp[1001][1001];
void print(int h, int w){
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout << dp[i][j] <<" ";
		}cout <<endl;
	}
}
int main(){
	int h, w;
	cin >> h >> w;
	//vector<vector<int>> a(h, vector<int>(w));
	memset(dp, 0, sizeof(dp));
	dp[h-1][w-1] = 1;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			char x;
			cin >> x;
			// a[i][j] = x == '.' ? 0: 1;
			if(x == '#')dp[i][j] = -1;
		}
	}
	//print(h, w);
	for(int j = w-2; j >= 0; j--){
		if(dp[h-1][j] == -1)continue;
		if(dp[h-1][j+1] != -1)dp[h-1][j] = dp[h-1][j+1];
		else dp[h-1][j] = -1;
	}
	//print(h, w);
	for(int i = h-2; i >= 0; i--){
		if(dp[i][w-1] == -1)continue;
		if(dp[i+1][w-1] != -1)dp[i][w-1] = dp[i+1][w-1];
		else dp[i][w-1] = -1;
	}
	//print(h, w);
	for(int i = h-2; i >= 0; i--){
		for(int j = w-2; j >= 0; j--){
			if(dp[i][j] == -1)continue;
			if(dp[i+1][j] == -1 && dp[i][j+1] == -1){
				dp[i][j] = -1;
			}
			else if(dp[i+1][j] == -1){
				dp[i][j] = dp[i][j+1];
			}
			else if(dp[i][j+1] == -1){
				dp[i][j] = dp[i+1][j];
			}
			else {
				dp[i][j] = (dp[i+1][j]%mod + dp[i][j+1]%mod)%mod;
			}
		}
	}
	if(dp[0][0] != -1){
		cout << dp[0][0] << endl;
	}
	else cout << 0 << endl;
	//print(h, w);

}