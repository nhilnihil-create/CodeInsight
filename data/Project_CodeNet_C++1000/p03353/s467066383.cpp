#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  if(s.size()==1) {
    cout << s << endl;
    return 0;
  }
  vector<string> vec;
  rep(i,s.size())for(int j = 1; j<=5 && i+j<=s.size(); j++) {
    string t;
    t = s.substr(i,j);
    vec.push_back(t);
  }
  sort(vec.begin(),vec.end());
  int cnt = 1;
  rep(i,vec.size()-1) {
    if(vec.at(i) != vec.at(i+1)) cnt++;
    if(cnt == k) {
      cout << vec.at(i+1) << endl;
      return 0;
    }
  }
}