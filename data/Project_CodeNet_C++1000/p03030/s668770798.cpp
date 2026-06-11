#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


int main(){
  int n;
  cin >> n;
  vector<pair<string, int>> rest(n);
  vector<pair<string, int>> rest_s(n);
  REP(i,n){
    string s;
    int p;
    cin >> s >> p;
    rest[i].first = s;
    rest[i].second = -p;
    rest_s[i].first = s;
    rest_s[i].second = -p;
  }

  sort(ALL(rest_s));

  //REP(j,n) cout <<j + 1<< ": "<< rest_s[j].first << rest_s[j].second  << endl;


  REP(i,n){
    REP(j,n){
      if(rest[j] == rest_s[i]){
        cout << j + 1 << endl;
        break;
      }
    }
  }

  //mapの内部ではKEYが昇順になるようにsortされている

  return 0;
}
