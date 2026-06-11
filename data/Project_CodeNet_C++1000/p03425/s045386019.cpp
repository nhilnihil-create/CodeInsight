#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll n; cin>>n;
  vector<ll> v(5);
  rep(i,n){
    string s; cin>>s;
    if(s.at(0)=='M'){v[0]++;}
    if(s.at(0)=='A'){v[1]++;}
    if(s.at(0)=='R'){v[2]++;}
    if(s.at(0)=='C'){v[3]++;}
    if(s.at(0)=='H'){v[4]++;}
  }
  ll a= v[0]*v[1]*(v[2]+v[3]+v[4])
    +v[0]*v[2]*(v[3]+v[4])
    +(v[0]+v[1]+v[2])*v[3]*v[4]
    +v[1]*v[2]*(v[3]+v[4]);
  cout<<a;
}