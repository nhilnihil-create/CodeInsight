#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int d; cin >> d;
  string ev = "";
  rep(i,25-d){
    ev += " Eve";
  }
  string ans = "Christmas";
  ans+=ev;

  cout << ans << endl;
  
  return 0;
}
