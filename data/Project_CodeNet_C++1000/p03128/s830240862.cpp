#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1LL << 60;
constexpr int INF = 3000000007;
const double INFD = 1e100;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------
const string MINUSINF = "-";
ll match[10] = {2,5,5,4,5,6,3,7,6};
string dp[11000];


void chmax(string &a, string b){
  if(a == MINUSINF) a = b;
  if(a.size() < b.size()) a = b;
  else if(a.size() == b.size()){
    if(a < b) a = b;
  }
}

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> A(M);
  for(int i=0; i<M; i++){
    cin >> A[i];
  }
  for(int i=0; i<11000; i++){
    dp[i] = MINUSINF;
  }
  dp[0] = "";
  for(int i=0; i<=N; i++){
    if(dp[i] == MINUSINF) continue;
    for(auto a : A){
      chmax(dp[i+match[a-1]],dp[i] + (char)('0' + a));
    }
  }
  cout << dp[N] << endl;
  return 0;
}
