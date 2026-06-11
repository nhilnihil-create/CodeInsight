#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

int f(int x){
  if(x%2 == 0) return x/2;
  else return 3*x + 1;
}

int main(){
  int s;
  cin >> s;
  const int INF = 1000005;
  vector<int> a(INF);

  REP(i,INF){
    if(i == 0){
      a[i] = s;
      continue;
    }
    a[i] = f(a[i-1]);
  }

  vector<int> b(INF);

  REP(i,INF) b[i] = 0;

  REP(i,INF){
    ++b[a[i]];
    if(b[a[i]] > 1){
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
