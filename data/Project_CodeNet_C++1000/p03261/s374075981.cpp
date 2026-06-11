#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n;
  cin >> n;
  vector<string> word(n);
  map<string, int> mp;
  bool ok = true;
 
  REP(i,n){
    string  w;
    cin >> w;
    word[i] = w;
    mp[w]++;
    if(mp[w] == 2){
      ok = false;
    }
    if(i == 0) continue;
    if(*word[i-1].rbegin() != *word[i].begin()) ok = false;
  }

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
