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
using pil = pair<int, long>;
using pll = pair<long, long>;
using vc = vector<char>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
  int n;
  cin >> n;
  vi b(n);
  rep(i,n){
    int a;
    cin >> a;
    if(a > i+1){
      cout << -1 << endl;
      return 0;
    }
    b.at(i) = a;
  }
  vb seen(n, false);
  vi ans;
  rep(i,n){
    int comp = n-i;
    for(int j=n-1; j>=0; j--){
      if(seen.at(j)) continue;
      if(b.at(j) == comp){
        ans.push_back(comp);
        seen.at(j) = true;
        break;
      }
      comp--;
    }
  }
  rep(i,ans.size()){
    cout << ans.at(ans.size()-1-i) << endl;
  }
}