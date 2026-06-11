#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 5100000
#define MOD 1000000007
#define INF 100000000000000

int main(){
  int X,Y,Z,K;
  cin>>X>>Y>>Z>>K;
  vector<ll> A(X),B(Y),C(Z);
  for(int i=0;i<X;i++){
    cin>>A.at(i);
  }
  for(int i=0;i<Y;i++){
    cin>>B.at(i);
  }
  for(int i=0;i<Z;i++){
    cin>>C.at(i);
  }
  vector<ll> AB;
  for(int i=0;i<X;i++){
    for(int j=0;j<Y;j++){
      AB.push_back(A.at(i)+B.at(j));
    }
  }
  sort(AB.begin(),AB.end());
  reverse(AB.begin(),AB.end());
  sort(C.begin(),C.end());
  reverse(C.begin(),C.end());

  ll left=-1;
  ll right=30000000003;

  while(left+1<right){
    ll x=(left+right)/2;
    ll count=0;
    ll j=Z-1;
    for(ll i=0;i<X*Y&&j>=0;i++){
      while(AB.at(i)+C.at(j)<x){
        j--;
        if(j<0){
          break;
        }
      }
      count+=j+1;
    }
    if(count<K){
      right=x;
    }else{
      left=x;
    }
  }
  ll x=left+1;
  vector<ll> ans;
  for(int i=0;i<X*Y;i++){
    for(int j=0;j<Z;j++){
      if(AB.at(i)+C.at(j)>=x){
        ans.push_back(AB.at(i)+C.at(j));
      }else{
        break;
      }
    }
  }
  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());
  ll n=ans.size();
  for(int i=0;i<n;i++){
    cout<<ans.at(i)<<endl;
  }
  for(int i=0;i<K-n;i++){
    cout<<x-1<<endl;
  }
}
