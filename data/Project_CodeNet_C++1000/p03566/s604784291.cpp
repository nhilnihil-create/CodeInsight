#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> t(N+1), v(N+1);
  for (int i=0; i<N; i++) cin >> t[i];
  for (int i=0; i<N; i++) cin >> v[i];
  int tsum = 0;
  for (int i=0; i<N; i++) tsum += t[i];
  v[N] = 0;
  vector<double> speed(tsum*2+1,1e6);
  int tm = 0;
  for (int i=0; i<=N; i++){
    tm += t[i]*2;
    int ve = v[i+1];
    for (int j=tm; j>=0; j--){
      speed[j] = min(speed[j], ve + (tm-j)*0.5);
    }
  }
  tm = 0;
  for (int i=0; i<N; i++){
    for (int j=tm; j<=tm+2*t[i]; j++){
      speed[j] = min((double)v[i], speed[j]);
    }
    tm += t[i]*2;
  }
  double ans = 0;
  double befsp = 0;
  for (int i=1; i<=tsum*2; i++){
    // cout << befsp << endl;
    ans += (befsp+min(speed[i],befsp+0.5))*0.5*0.5;
    befsp = min(speed[i],befsp+0.5);
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}
