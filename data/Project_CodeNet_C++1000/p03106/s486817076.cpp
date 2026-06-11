#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int a, b, k;
  cin >> a >> b >>k;
  int cnt = 0;
  vector<int> d;
  REP2(i,1,101){
    if(a%i == 0 && b%i == 0){
      d.push_back(i);
    }
  }

  int x = d.size() - k;
  //REP(i,d.size()) cout << d[i] << endl;
  cout << d[x] << endl;
  return 0;
}