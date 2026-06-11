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
#define INF (1LL<<60)
#define EPS (1e-10)
typedef __int128 Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

long long  n, X;
long long res = INF;
long long sum[216000];
Int solve(Int robot){
  Int res = (robot + n) * X;
  Int cnt = 1;
  for(Int i = n-1;i >= 0;i-=robot){
    Int r = i;
    Int l = max(0, r - robot + 1);
    Int tmp= sum[r];
    if(l)tmp -= sum[l-1];
    res += tmp * (max(cnt, 2) * 2 + 1);
    cnt++;
  }
  return res;
}

int main(){
  cin >> n >> X;
  for(Int i = 0;i < n;i++){
    cin >> sum[i];
    if(i)sum[i] += sum[i-1];
  }
  for(Int i = 1;i <= n;i++){
    //    cout << i << " " << solve(i) << endl;
    res = min(res, solve(i));
  }
  cout << res << endl;
  return 0;
}