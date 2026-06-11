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
#include<string>
#include<cstdlib>
#include<cctype>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1LL<<60;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------

int main(){
  int N,C;
  cin >> N >> C;
  vector<vector<int>> value(C+1,vector<int> (C+1));
  for(int i=1; i<=C; i++){
    for(int j=1; j<=C; j++){
      cin >> value[i][j];
    }
  }
  vector<vector<int>> G(N+1, vector<int> (N+1));
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      cin >> G[i][j];
    }
  }
  vector<vector<int>> sum(3,vector<int> (C+1,0));
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      sum[(i+j)%3][G[i][j]]++;
    }
  }
  int ans = 1e9;
  for(int i=1; i<=C; i++){
    for(int j=1; j<=C; j++){
      for(int k=1; k<=C; k++){
        if(i==j || i==k || j==k) continue;
        int temp = 0;
        for(int l=1; l<=C; l++){
          if(i==l) continue;
          temp += sum[0][l]*value[l][i];
        }
        for(int l=1; l<=C; l++){
          if(j==l) continue;
          temp += sum[1][l]*value[l][j];
        }
        for(int l=1; l<=C; l++){
          if(k==l) continue;
          temp += sum[2][l]*value[l][k];
        }
        chmin(ans,temp);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
