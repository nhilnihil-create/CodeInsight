#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  double n,t,a;
  cin >> n >> t >> a;
  vector<double> h(n);
  rep(i,n){
    cin >> h.at(i);
  }
  double ans=0,mini=10000001;
  rep(i,n){
    double tem=t-0.006*h.at(i);
    if(mini>abs(tem-a)){
      mini=abs(tem-a);
      ans=i+1;
    }
  }
  cout << ans;
}
