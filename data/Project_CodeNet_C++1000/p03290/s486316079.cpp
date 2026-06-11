#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int d, g;
  cin >> d >> g;
  g /= 100;
  int p[d], c[d];
  for(int i=0; i<d; i++){
    cin >> p[i] >> c[i];
    c[i] /= 100;
  }
  int n = 1<<d;
  int ans = 1000000009;
  for(int i=0; i<n; i++){
    int tmp = 0, cnt = 0, ma = 0;
    for(int bit=0; bit<d; bit++){
      if(i&(1<<bit)){
        tmp += p[bit]*(bit+1) + c[bit];
        cnt += p[bit];
      }else{
        ma = max(ma, bit+1);
      }
    }
    if(g<=tmp+p[ma-1]*ma){
      if(ma>0) cnt += max(0,(g-tmp+ma-1)/ma);
      ans = min(ans, cnt);
    }
  }
  cout << ans << endl;
  return 0;
}
