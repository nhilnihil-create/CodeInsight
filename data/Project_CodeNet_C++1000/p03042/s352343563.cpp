#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int s; cin >> s;
  int pre = s/100;
  int suf = s%100;

  bool YYMM = (1<=suf && suf<=12) ? true:false;
  bool MMYY = (1<=pre && pre<=12) ? true:false;

  if(YYMM && MMYY) cout << "AMBIGUOUS" << endl;
  else if(YYMM) cout << "YYMM" << endl;
  else if(MMYY) cout << "MMYY" << endl;
  else cout << "NA" << endl;
  
  return 0;
}
