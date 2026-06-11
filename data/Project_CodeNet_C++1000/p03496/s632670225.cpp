#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  int n;
  cin >> n;
  vi a(n);
  int mini = 1e9;
  int minid;
  int maxi = -1e9;
  int maxid;
  rep(i,n){
    cin >> a.at(i);
    if(a.at(i) > maxi){
      maxi = a.at(i);
      maxid = i;
    }
    if(a.at(i) < mini){
      mini = a.at(i);
      minid = i;
    }
  }
  cout << 2*n - 1 << endl;
  if(abs(maxi) > abs(mini)){
    rep(i,n) cout << maxid+1 << " " << i+1 << endl;
    rep(i,n-1) cout << i+1 << " " << i+2 << endl;
  }else{
    rep(i,n) cout << minid+1 << " " << i+1 << endl;
    rep(i,n-1) cout << n-i << " " << n-i-1 << endl;
  }
}
