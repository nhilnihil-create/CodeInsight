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
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
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
  vector<vector<int>> a(C, vector<int> (1e5+10,0));
  for(int i=0; i<N; i++){
    int s,t,c;
    cin >> s >> t >> c;
    c--;
    a[c][s]++;
    a[c][t+1]--;
  }
  vector<vector<int>> sum(C, vector<int> (1e5+10,0));
  for(int i=0; i<C; i++){
    sum[i][0] = a[i][0];
    for(int j=0; j<1e5+5; j++){
      sum[i][j+1] = sum[i][j]+a[i][j+1];
    }
  }
  int ans = 0;
  for(int i=0; i<1e5+5; i++){
    int cnt = 0;
    for(int j=0; j<C; j++){
      if(sum[j][i]){
        cnt++;
      }
    }
    chmax(ans,cnt);
  }
  cout << ans << endl;
  return 0;
}
