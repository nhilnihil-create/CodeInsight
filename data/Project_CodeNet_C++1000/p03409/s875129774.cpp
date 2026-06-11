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

int main(){
  int N;
  cin >> N;
  vector<pair<int,int>> B(N),R(N);
  for(int i=0; i<N; i++){
    int a,b;
    cin >> a >> b;
    R[i] = make_pair(b,a);
  }
  for(int i=0; i<N; i++){
    int c,d;
    cin >> c >> d;
    B[i] = make_pair(c,d);
  }
  int ans=0;
  sort(B.begin(),B.end());
  sort(R.begin(),R.end(),greater<pair<int,int>>());
  vector<bool> id(N,false);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(id[j]) continue;
      if(R[j].second<B[i].first && R[j].first<B[i].second){
        ans++;
        id[j] = true;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
