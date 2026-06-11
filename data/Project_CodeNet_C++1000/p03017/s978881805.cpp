#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  a--,b--,c--,d--;
  string s;
  cin >> s;
  if(c > d){
    bool ok = false;
    REP(i,b,d + 1){
      int cnt = 0;
      rep(j,3)if(s[i + (j - 1)] == '.')cnt++;
      if(cnt == 3)ok = true; 
    }
    if(!ok){
      cout << "No" << endl;
      return 0;
    }
  }
  bool ok = true;
  REP(i,b,d){
   int cnt = 0;
   rep(j,2)if(s[i + j] == '#')cnt++;
   if(cnt == 2)ok = false;
  }
  REP(i,a,c){
    int cnt = 0;
    rep(j,2)if(s[i + j] == '#')cnt++;
    if(cnt == 2)ok = false;
  }
  if(ok)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
