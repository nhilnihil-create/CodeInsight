#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int dp[5400];
Int p[5400];
Int n, a, b;
int main(){
  fill(dp, dp + 5400, LINF);
  cin >> n >> a >> b;
  p[n] = n;
  for(int i = 0;i <= n;i++){
    if(i != n){cin >> p[i];p[i]--;}
    Int tmp = 0;
    Int maxima = -1;
    for(int j = i-1;j >= 0;j--){
      if(p[j] > p[i])tmp += a;
      else{
	if(p[j] > maxima){
	  dp[i] = min(dp[i], dp[j] + tmp);
	  maxima = p[j];
	}
	tmp += b;
      }
    }
    dp[i] = min(dp[i], tmp);
  }
  cout << dp[n] << endl;
  return 0;
}