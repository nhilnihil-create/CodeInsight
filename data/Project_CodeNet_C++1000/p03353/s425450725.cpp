#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;

int main(){
  string s;
  int k;
  cin >> s >> k;
  vector<string> d;
  rep(i, s.size()){
    string t = "";
    int a = min((int)s.size() - i, 5);
    rep(j, a){
      t += s[i+j];
      d.push_back(t);
    }
  }
  sort(ALL(d));
  string tmp = d[0];
  vector<string> v;
  for (int i = 1; i < d.size(); i++){
    if (d[i] != tmp){
      v.push_back(tmp);
      tmp = d[i];
    }
  }
  v.push_back(tmp);
  cout << v[k-1] << endl;
}