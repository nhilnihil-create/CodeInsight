#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  (a).begin(),(a).end()
#define P pair<int, int>
#define ll long long
const int MOD = 1000000007;
//bitset<64>(x).count()
//fixed << setprecision(15) << 

int main(){
  int m[3][3];
  rep(i, 3){
    rep(j, 3)
      cin >> m[i][j];
  }
  int a[3], b[3]={};
  rep(i,3)
    a[i] = m[i][0];
  b[1] = m[0][1] - a[0];
  b[2] = m[0][2] - a[0];
  string ans = "Yes";
  rep(i, 3){
    rep(j, 3){
      if(m[i][j]!=a[i]+b[j])
        ans = "No";
    }
  }
  cout << ans << endl;
}
