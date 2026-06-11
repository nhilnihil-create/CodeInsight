#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  int ans = 0;
  rep(i,n-1){
    if(a.at(i) == a.at(i+1)){
      a.at(i+1) = -1;
      ans++;
    }
  }
  cout << ans << endl;
}
