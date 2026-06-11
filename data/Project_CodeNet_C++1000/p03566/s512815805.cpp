#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int t[n],T = 0;
  for(int i = 0;i < n;i++){
    cin >> t[i];
    T += t[i];
  }
  double v[2*T+1];
  for(int i = 0;i < 2*T+1;i++){
    v[i] = 1000000;
  }
  int tsum = 0;
  for(int i = 0;i < n;i++){
    double vc;
    cin >> vc;
    for(int j = tsum;j <= tsum + 2*t[i];j++){
      v[j] = min(v[j],vc);
    }
    tsum += 2*t[i];
  }
  v[0] = 0;
  v[2*T] = 0;
  for(int i = 1;i < 2*T+1;i++){
    v[i] = min(v[i-1]+0.5,v[i]);
  }
  for(int i = 2*T-1;i > 0;i--){
    v[i] = min(v[i+1]+0.5,v[i]);
  }
  for(int i = 0;i <= 2*T;i++){
    //cout << i/2 << ' ' <<  v[i] << endl;
  }
  double result = 0;
  for(int i = 0;i < 2*T;i++){
    result += (v[i] + v[i+1])*0.25;
  }
  printf("%.16f\n", result);
}