#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<ll> count(5,0); //MARCH
  rep(i,n){
    string s;
    cin >> s;
    if(s.at(0)=='M') count.at(0)++;
    else if(s.at(0)=='A') count.at(1)++;
    else if(s.at(0)=='R') count.at(2)++;
    else if(s.at(0)=='C') count.at(3)++;
    else if(s.at(0)=='H') count.at(4)++;
  }

  ll ans=0;
  for(int i=0; i<3; i++){
    for(int j=i+1; j<4; j++){
      for(int k=j+1; k<5; k++){
        ll p = count.at(i)*count.at(j)*count.at(k);
        ans += p;
      }
    }
  }

  cout << ans;
}