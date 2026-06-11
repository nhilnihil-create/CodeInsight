#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  int N;
  cin >> N;
  
  int t[100010];
  int x[100010];
  int y[100010];
  t[0] = x[0] = y[0] = 0;
  
  rep(i,N){
    cin >> t[i+1] >> x[i+1] >> y[i+1];
  }
  
  bool can = true;
  rep(i,N){
    int time = t[i+1]-t[i];
    int dist = abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
    if(time < dist) can = false;
    if(time%2 != dist%2) can = false;
  }
  
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
