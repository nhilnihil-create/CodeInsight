#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  ll ans=1,sum=1;
  rep(i,n){
    sum*=3;
    if(a.at(i)%2==0){
      ans*=2;
    }
  }
  cout << sum-ans;
  
}
