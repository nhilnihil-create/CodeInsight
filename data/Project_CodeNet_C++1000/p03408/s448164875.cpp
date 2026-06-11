#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)   for(int i=(a)  ;i<(b) ;i++)
#define RFOR(i,a,b)  for(int i=(b)-1;i>=(a);i--)
#define REP(i,n)     for(int i=0    ;i<(n) ;i++)
#define RREP(i,n)    for(int i=(n)-1;i>=0  ;i--)
#define EACH(i,a,b)  for(int i=(a)  ;i<=(b);i++)
#define REACH(i,a,b) for(int i=(b)  ;i>=(a);i--)
#define ALL(a)       (a).begin(), (a).end()
#define RALL(a)      (a).rbegin(), (a).rend()

int main() {
  int n, m, price;
  cin >> n;
  vector<string> blue(n);
  REP(i,n) cin >> blue[i];
  
  cin >> m;
  vector<string> red(m);
  price = 0;
  REP(i,m) cin >> red[i];
  
  for(int i=0; i<n; i++){
    string s = blue[i];
    int temp = 0;
    for(int j=0; j<n; j++){
      if(s == blue[j]){
        temp += 1;
      }
    }
    for(int j=0; j<m; j++){
      if(s == red[j]){
        temp -= 1;
      }
    }
    if(price < temp) price = temp;
  }
  cout << price << endl;

  return 0;
}