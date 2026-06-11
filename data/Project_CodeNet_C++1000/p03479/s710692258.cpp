#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int  main(){
  ll x,y;cin>>x>>y;
  int c=1;
  while(true){
    if(2*x>y){break;}
    x*=2;c++;
  }
  cout<<c;
}