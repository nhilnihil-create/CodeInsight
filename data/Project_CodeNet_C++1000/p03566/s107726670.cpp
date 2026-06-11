#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  double ans = 0.0, nowv = 0.0, nowt = 0.0, lim = 0.0;
  cin >> n ;
  int t[n+1], sumt=0;
  int cnt = 1;
  t[0] = 0;
  int v[n+2];
  v[n+1] = 0;
  v[0] = 0;
  for(int i=1;i<=n;i++){
    cin >> t[i];
    sumt += t[i];
    t[i] = sumt;
  }
  for(int i=1;i<=n;i++){
    cin >> v[i];
  }
  for(double i = 0.5; i<=sumt;i+=0.5){
    if(i > t[cnt]) cnt++;
    double lim = v[cnt];
    double tmp;
    for(int j=0;j<=n;j++){
      if(j < cnt){
        tmp = v[j] + i - t[j];
      }else{
        tmp = v[j+1] + t[j] - i;
      }
      lim = min(lim, tmp);
    }
    if(nowv<lim){
      ans += (nowv/2) + 0.25;
      nowv += 0.5;
    }else if(nowv>lim){
      ans += (nowv/2) - 0.25;
      nowv -= 0.5;
    }else{
      ans += (nowv/2);
    }
  }
  cout << fixed << setprecision(8) <<  ans << endl;
}