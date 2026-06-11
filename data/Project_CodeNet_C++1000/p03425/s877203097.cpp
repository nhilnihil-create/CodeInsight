#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<string> s(n);
  vector<ll> p(5);
  rep(i,n){
    cin >> s.at(i);
    if(s.at(i).at(0)=='M'){
      p.at(0)++;
    }
    if(s.at(i).at(0)=='A'){
      p.at(1)++;
    }
    if(s.at(i).at(0)=='R'){
      p.at(2)++;
    }
    if(s.at(i).at(0)=='C'){
      p.at(3)++;
    }
    if(s.at(i).at(0)=='H'){
      p.at(4)++;
    }
  }
  ll ans=0;
  int i,j,k;
  for(i=0;i<3;i++){
    for(j=i+1;j<4;j++){
      for(k=j+1;k<5;k++){
        ans+=p.at(i)*p.at(j)*p.at(k);
      }
    }
  }
  cout << ans;
}
