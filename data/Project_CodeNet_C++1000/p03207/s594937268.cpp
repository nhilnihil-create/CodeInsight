#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int  main(){
  int n;cin>>n;
  int sum=0;
  int p,pm=0;
  rep(i,n){
    cin>>p;
    pm=max(pm,p);
    sum+=p;
  }
  cout<<sum-pm/2;
}