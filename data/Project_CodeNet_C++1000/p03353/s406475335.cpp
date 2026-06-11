#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
  string s; ll k;
  cin >> s >> k;
  map<string, bool> b;
  vector<string> c;
  // 文字数1-kまでやれば十分(a,aa,aaa,aaaa,aaaaa)、ただしsの方が短い可能性がある
  rep(i,0,s.size()){
    rep(j,0,min(k, (ll)s.size()-i)){
      auto t = s.substr(i,j+1);
      if(!b[t]) c.push_back(t);
      b[t] = true;
    }
  }
  sort(c.begin(), c.end());
  cout << c[k-1] << endl;
  return 0; 
}