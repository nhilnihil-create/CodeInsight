#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

bool prime(int x){
    if(x==1)return false;
    for(int i=2; i<=pow(x,0.5); i++){
        if(x%i==0)return false;
    }
    return true;
}

int like2017(int j){
  if(prime((j+1)/2) && prime(j)){return 1;}
  return 0;
}

int main() {
  int n; cin>>n;
  int l,r;
  vector<int> v(50000);
  rep(i,50000){
    if(i==0){v[0]=like2017(1);}
    else{v[i]=v[i-1]+like2017(2*i+1);}
  }
  rep(i,n){
    cin>>l>>r;
    if(l==1){cout<<v[(r-1)/2]<<endl;}
    else{cout<<v[(r-1)/2]-v[(l-3)/2]<<endl;}
  }
}