#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t,a; cin >> n >> t >> a;
  int h;
  double temp;
  double m_temp = 1000000000;
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> h;
    temp = t - h * 0.006;
    //cout << temp << endl;
    if(abs(temp - a) < abs(m_temp - a)){
      ans = i + 1;
      m_temp = temp;
    }
  }
  cout << ans;
  
}