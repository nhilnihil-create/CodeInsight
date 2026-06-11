#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,t,a;
  cin >> n >> t >> a;
  vector<int> h(n);
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  vector<double> ans(n);
  for(int i = 0; i < n; i++){
    ans[i] = t-h[i]*0.006;
  }
  double ans1 = 1000000,ans2;
  for(int i = 0; i < n; i++){
    if(ans1 > abs(ans[i]-a)){
      ans2 = i+1;
      ans1 = abs(ans[i]-a);
    }
  }
  cout << ans2 << endl;
}