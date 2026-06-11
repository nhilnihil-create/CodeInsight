#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int bit = 1 << n;
  bit <<= n;
  int l[n];
  for(int i=0; i<n; i++){
    cin >> l[i];
  }
  int ans = 1000000009;
  for(int i=1; i<bit; i++){
    int ta=0, tb=0, tc=0;
    int tmp = i;
    int cnt = 0;
    for(int j=0; j<n; j++){
      int k = tmp % 4;
      tmp >>= 2;
      if(k==0) continue;
      if(k==1){
        if(ta!=0) cnt++;
        ta += l[j];
      }
      if(k==2){
        if(tb!=0) cnt++;
        tb += l[j];
      }
      if(k==3){
        if(tc!=0) cnt++;
        tc += l[j];
      }
    }
    if(ta==0||tb==0||tc==0) continue;
    cnt *= 10;
    cnt += abs(ta-a) + abs(tb-b) + abs(tc-c);
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
