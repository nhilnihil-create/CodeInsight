#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int H,W; cin >> H >> W;
  int h,w; cin >> h >> w;

  int num = H*W;
  num-=h*W;
  num-=w*(H-h);

  cout << num << endl;
  
  return 0;
}
