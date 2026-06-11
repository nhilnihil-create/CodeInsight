#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n,a;
  double t;
  cin >> n >> t >> a;
  vector<double> x(n);
  
  for (int i=0;i<n;i++){
    double h;
    cin >> h;
    x[i] = abs(t-h*6/1000-a);
  }
  
  int ans =0;
  
  for (int i=1;i<n;i++){
    if(x[ans]>x[i]) ans = i;
  }
  
  cout << ans+1 << endl;
  
    
    
}
