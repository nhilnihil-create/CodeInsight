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
  string s;
  cin >> s;
  int n = s.size();
  int l = n/2;
  int r = n/2;
  char ll = s.at(l);
  char rr = s.at(r);
  while(l > 0){
    l--;
    if(s.at(l) != ll){
      l++;
      break;
    }
  }
  while(r < n-1){
    r++;
    if(s.at(r) != rr){
      r--;
      break;
    }
  }
  //cout << r << " " << l << endl;
  cout << min(r+1,n-l) << endl;
}