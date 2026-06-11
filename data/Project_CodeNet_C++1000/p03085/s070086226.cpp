#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  char b; cin >> b;

  if(b=='A') cout << "T" << endl;
  else if(b=='C') cout << "G" << endl;
  else if(b=='G') cout << "C" << endl;
  else if(b=='T') cout << "A" << endl;
    
  return 0;
}
