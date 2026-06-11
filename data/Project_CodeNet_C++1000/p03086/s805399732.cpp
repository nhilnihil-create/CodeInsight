#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  string s;
  cin >> s;
  vector<int> bubun;
  string t = "";
  rep(i,s.size()){
    if(s[i]=='A'||s[i]=='G'||s[i]=='C'||s[i]=='T') t += s[i];
    else {
      bubun.push_back(t.size());
      t = "";
    }
  }
  if(t!="") bubun.push_back(t.size());
  sort(bubun.rbegin(),bubun.rend());
  cout << bubun[0] << endl;
}
