#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  string year="";
  rep(i,4) year+=s[i];
  int y = stoi(year);
  string month = "";
  rep(i,2) month+=s[i+5];
  int m = stoi(month);
  string day = "";
  rep(i,2) day+=s[s.size()-1-1+i];
  int d = stoi(day);

  bool heisei = true;
  if(y>=2020) heisei = false;
  else if(m>=5) heisei = false;
  else if(m==4 && d>=31) heisei = false;

  if(heisei) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
  
  return 0;
}
