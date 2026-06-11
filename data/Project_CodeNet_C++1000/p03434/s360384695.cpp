#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)   for(int i=(a)  ;i<(b) ;i++)
#define RFOR(i,a,b)  for(int i=(b)-1;i>=(a);i--)
#define rep(i,n)     for(int i=0    ;i<(n) ;i++)
#define rrep(i,n)    for(int i=(n)-1;i>=0  ;i--)
#define each(i,a,b)  for(int i=(a)  ;i<=(b);i++)
#define reach(i,a,b) for(int i=(b)  ;i>=(a);i--)
#define all(a)       (a).begin(), (a).end()
#define rall(a)      (a).rbegin(), (a).rend()

int main() {
  int n;
  cin >> n;
  vector<int> vc(n);
  rep(i, n) cin >> vc[i];
  int alice = 0, bob = 0;
  
  rep(i, n/2){
    int index = 0;
    int max_val = 0;
    rep(j, vc.size()){
      if(vc[j] > max_val){
        index = j;
        max_val = vc[j];
      }
    }
    alice += max_val;
    vc.erase(vc.begin() + index);
    index = 0;
    max_val = 0;
    rep(j, vc.size()){
      if(vc[j] > max_val){
        index = j;
        max_val = vc[j];
      }
    }
    bob += max_val;
    vc.erase(vc.begin() + index);
  }
  if(n % 2 == 1) {
    alice += vc[0];
  }
  cout << alice - bob << endl;
  return 0;
}