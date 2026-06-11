#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int r; cin >> r;
  
  if(r<1200) cout << "ABC" << endl;
  else if(r<2800) cout << "ARC" << endl;
  else cout << "AGC" << endl;
  
  return 0;
}
