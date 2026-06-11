#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  double ans = 0.0, nowv = 0.0, lim = 0.0;
  cin >> n ;
  int t[n+1], v[n+2], cnt = 1;
  t[0] = 0;
  v[n+1] = 0;
  v[0] = 0;
  for(int i=1;i<=n;i++){
    cin >> t[i];
    t[i] += t[i-1];
  }
  for(int i=1;i<=n;i++){
    cin >> v[i];
  }
  for(double i = 0.5; i<=t[n];i+=0.5){
    if(i > t[cnt]) cnt++;
    double lim = v[cnt];
    for(int j=0;j<=n;j++){
      lim = min(lim, (j < cnt?(v[j] + i - t[j]):(v[j+1] + t[j] - i)));
    }
    ans += (nowv/2);
    if(nowv<lim){
      ans += 0.25;
      nowv += 0.5;
    }else if(nowv>lim){
      ans -= 0.25;
      nowv -= 0.5;
    }
  }
  cout << fixed << setprecision(8) <<  ans << endl;
}