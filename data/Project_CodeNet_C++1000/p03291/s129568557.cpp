#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
using namespace std;
#define INF 1000000007
#define LINF 8000000000000000007
#define MOD 1000000007
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 1
#ifdef MODE
#define DEB(X) cout << #X << ": " << X << " ";
#define ARDEB(i, X) cout << #X << "[" << i << "]: " << X[i] << " ";
#define END cout << endl;
#else
#define DEB(X) \
    {          \
    }
#define ARDEB(i, X) \
    {               \
    }
#define END \
    {       \
    }
#endif
typedef pair<int, int> P;
struct edge{int to,cost;};

typedef long long ll;

using namespace std;


int ans,ans2;
string s;
int dp[111111][11];

signed main(){
	cin>>s;
	for(int i=s.size();i>=0;i--){
		for(int j=3;j>=0;j--){
			if(i==s.size()){
				if(j==3)dp[i][j]=1;
				else dp[i][j]=0;
			}
			else{
				if(s[i]=='?')dp[i][j]+=dp[i+1][j]*3;
				else dp[i][j]+=dp[i+1][j];
				if(j<3/*(３つ選び終わってない)*/ && (s[i]=='?' || s[i]=="ABC"[j])){//選んだj文字目が?もしくは「1文字目ならA,2文字目ならB,3文字目ならC」
					dp[i][j]+=dp[i+1][j+1];
				}
			}
			dp[i][j]%=MOD;
		}
	}
	cout<<dp[0][0]<<endl;
}
