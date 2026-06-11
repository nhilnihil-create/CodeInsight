#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
  int n;
  cin >> n;
  vector<tuple<string,int,int>> a(n);
  rep(i,n){
    string s;
    int p;
    cin >> s >> p;
    a.at(i) = make_tuple(s,-p,i+1);
  }
  sort(a.begin(),a.end());
  rep(i,n) cout << get<2>(a.at(i)) << endl;
  
}
