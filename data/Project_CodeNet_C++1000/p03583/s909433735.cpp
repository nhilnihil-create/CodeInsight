#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  double n; cin >> n;
  rep(i,3501) rep(j,3501){
    if(i==0 || j==0 || 4*i*j-n*i-n*j<=0) continue;
    double w = (n*i*j)/(4*i*j-n*i-n*j);
    if(ceil(w) == floor(w)){
      cout << i << " " << j << " " << int(w) << endl;
      return 0;
    }
  }
  cout << "\n";
  return 0;
}
