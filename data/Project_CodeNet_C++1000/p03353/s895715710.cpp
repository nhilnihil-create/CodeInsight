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
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF = 1LL << 40;
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
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------

template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}
// v = compress(v);


int main(){
  string s;
  cin >> s;
  int K;
  cin >> K;
  vector<string> vec;
  for(int i=1; i<=min(5,(int)s.size()); i++){
    for(int j=0; j<s.size()-i+1; j++){
      vec.push_back(s.substr(j,i));
    }
  }
  vec = compress(vec);
  sort(vec.begin(),vec.end());
  cout << vec[K-1] << endl;
  return 0;
}
