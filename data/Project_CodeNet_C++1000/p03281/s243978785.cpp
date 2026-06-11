#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define All(a) (a).begin(),(a).end()


vector<ll> prime_factorization(ll x){
  vector<ll> v;
  ll i;
  for (i=2; i<x; i++){
    if(x%i==0){
      v.push_back(i);
      while(x%i==0)x/=i;
    }
  }
  if(x!=1)v.push_back(x);
  return v;
}


int main(){ 
  int n,cnt,cnt_2=0;
  set<ll> s;
  cin >> n;
  int tmp=1;
  while(tmp<=n){
    cnt=0;
    for(int i=1; i <= tmp; i++){        
      if(tmp%i==0)cnt++;
      //code
    }
    if(cnt==8)cnt_2++;
    tmp+=2;
  }
  cout << cnt_2<<endl;
  return 0;
}