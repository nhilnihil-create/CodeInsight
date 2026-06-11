#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;


int dp[301][301][301];
void solve(std::string S, long long K){
	for(int w=1;w<=S.size();w++){
		for(int i=0;i+w<=S.size();i++){
			for(int k=0;k<=K;k++){
				dp[i][i+w][k]=max(dp[i][i+w-1][k],dp[i+1][i+w][k]);
				if(k>0){
					dp[i][i+w][k]=max(dp[i][i+w][k],dp[i][i+w][k-1]);
				}
				if(S[i]==S[i+w-1]){
					int d=(w==1?1:2);
					dp[i][i+w][k]=max(dp[i][i+w][k],dp[i+1][i+w-1][k]+d);
				}
				else{
					if(k>0){
						dp[i][i+w][k]=max(dp[i][i+w][k],dp[i+1][i+w-1][k-1]+2);
					}
				}
			}
		}
	}
	cout << dp[0][S.size()][K] << endl;

}

int main(){
    std::string S;
    std::cin >> S;
    long long K;
    scanf("%lld",&K);
    solve(S, K);
    return 0;
}
