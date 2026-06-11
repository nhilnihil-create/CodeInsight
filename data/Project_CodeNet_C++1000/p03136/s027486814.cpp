#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int  main(){
  int n,sum=0; cin>>n;
  vector<int> v(n);
  rep(i,n){
    cin>>v.at(i);
    sum+=v.at(i);
  }
  sort(v.begin(),v.end());
  if(sum>2*v.at(n-1)){cout<<"Yes";}
  else{cout<<"No";}
}