#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
順列かな
いや
3333
順列でいくか
だいたい30個･･･
*/
int main(){
  ll N,ans=0; cin>>N;
  vector<ll> A(0,0);
  for(ll i=1; i<=7; i++){//3の数
    for(ll j=1; j<=8-i; j++){//5の数
      for(ll k=1; k<=9-i-j; k++){//7の数
        A.assign(0,0);
        for(ll ii=0; ii<i; ii++) A.emplace_back(3);
        for(ll jj=0; jj<j; jj++) A.emplace_back(5);
        for(ll kk=0; kk<k; kk++) A.emplace_back(7);
        ll cnt=i+j+k;
        do{
          ll m=0;
          for(ll n=0; n<cnt; n++) m=m*10+A[n];
          if(m<=N) ans++;
        }while(next_permutation(A.begin(), A.end()));
      }
    }
  }
  cout<<ans<<endl;
}