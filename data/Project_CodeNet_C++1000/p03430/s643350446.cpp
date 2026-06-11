#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int dp[310][310][310];

string s;
int K;

int saiki(int i,int j,int k){
	if(k>K)return 0;
	if(i==j)return 1;
	if(i>j)return 0;
	if(dp[i][j][k]!=0)return dp[i][j][k];
	if(s[i]==s[j]){
		return dp[i][j][k] = saiki(i+1,j-1,k)+2;
	}else{
		dp[i][j][k] = max(dp[i][j][k],saiki(i+1,j,k));
		dp[i][j][k] = max(dp[i][j][k],saiki(i,j-1,k));
		if(k!=K)dp[i][j][k] = max(dp[i][j][k],saiki(i+1,j-1,k+1)+2);
		return dp[i][j][k];
	}
}



int main(){
	cin >> s >> K;
	cout << saiki(0,s.size()-1,0) << endl;
	return 0;
}