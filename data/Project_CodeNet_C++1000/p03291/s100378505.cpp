#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
    string S;
	cin >> S;
	ll len=S.size();
	ll mod=1000000007;
	vector < vector <ll> > dp(len+2, vector<ll>(4, 0));
	dp[len+1][3]=1;
	for(int now=len; now>=1; now--){
		for(int i=0; i<4; i++){
			dp[now][i]=dp[now+1][i]%mod;
		}
		if(S[now-1]=='A'){
			dp[now][0]=(dp[now+1][0]+dp[now+1][1])%mod;
		}else if(S[now-1]=='B'){
			dp[now][1]=(dp[now+1][1]+dp[now+1][2])%mod;
		}else if(S[now-1]=='C'){
			dp[now][2]=(dp[now+1][2]+dp[now+1][3])%mod;
		}else{
			dp[now][0]=(dp[now+1][0]*3+dp[now+1][1])%mod;
			dp[now][1]=(dp[now+1][1]*3+dp[now+1][2])%mod;
			dp[now][2]=(dp[now+1][2]*3+dp[now+1][3])%mod;
			dp[now][3]=dp[now+1][3]*3%mod;
		}
	}
    cout << dp[1][0]%mod << endl;

    return 0;
}
