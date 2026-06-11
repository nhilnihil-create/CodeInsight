#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  ll n;
  cin>>n;
  vector<ll> v(n+10,0);
  for (int i = 1;i<=n;i++){
    cin>>v.at(i);
  }
  ll sum = 0;
  for (int i = 0;i<=n;i++){
    sum = sum + abs(v.at(i) - v.at(i+1));
  }
  for (int i = 1;i<=n;i++){
    cout << sum + abs(v.at(i-1) - v.at(i+1)) - (abs(v.at(i)-v.at(i+1)) + abs(v.at(i)-v.at(i-1))) << endl;
  }
}