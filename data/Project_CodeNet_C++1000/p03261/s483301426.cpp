#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  string ans = "Yes";
  set<string> box;
  string l;
  cin >> l;
  char last = l.at(l.size()-1);
  box.insert(l);
  rep(i,n-1){
    string s;
    cin >> s;
    if(box.count(s) || s.at(0) != last){
      ans = "No";
      break;
    }
    last = s.at(s.size()-1);
    box.insert(s);
  }
  cout << ans << endl;
}