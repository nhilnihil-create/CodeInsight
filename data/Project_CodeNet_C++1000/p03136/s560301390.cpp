#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n;
  cin >> n;
  vector<int> l(n);
  REP(i,n) cin >> l[i];

  sort(RALL(l));
  int ml = l[0];
  int sum = 0;
  for(int i = 1; i < n; ++i){
    sum += l[i];
  }

  if(ml < sum) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
