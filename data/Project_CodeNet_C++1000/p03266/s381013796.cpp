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
  ll N,K;
  cin >> N >> K;
  if(K%2){
    if(N < K){
      cout << 0 << endl;
    }else{
      ll res = 1;
      for(int i=0; i<3; i++){
        res *= N/K;
      }
      cout << res << endl;
    }
  }else{
    ll a,b;
    if(N<K){
      a = 0;
    }else{
      a = 1;
      for(int i=0; i<3; i++){
        a *= N/K;
      }
    }
    ll cnt = 0;
    ll half = K/2;
    while(half <= N){
      cnt++;
      half += K;
    }
    if(cnt){
      b = 1;
      for(int i=0; i<3; i++){
        b *= cnt;
      }
    }else{
      b = 0;
    }
    cout << a+b << endl;
  }
  return 0;
}
