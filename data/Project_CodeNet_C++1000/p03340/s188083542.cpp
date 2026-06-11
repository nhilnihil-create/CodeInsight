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
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  int l = 0;
  ll ans = 0;
  ll sum = 0;
  for(int r=0; r<N; r++){
    while(l<r){
      bool can = true;
      for(ll i=0; i<=20; i++){
        if(sum&(1LL<<i) && A[r]&(1LL<<i)){
          can = false;
        }
      }
      if(can){
        break;
      }
      // cout << "check:" << r << endl;
      // bitset<10> su(sum);
      // bitset<10> s(A[r]);
      // cout << s << endl;
      // cout << su << endl;
      sum -= A[l];
      l++;
    }
    sum += A[r];
    ans += (r-l+1);
  }
  cout << ans << endl;
  return 0;
}
