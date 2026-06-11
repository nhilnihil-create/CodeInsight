#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

int abs(int x){
  if(x<0){
    x=-x;
  }
  return x;
}

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin>>A.at(i);
    A.at(i)-=i+1;
  }
  sort(A.begin(),A.end());
  int x=A.at(N/2);
  ll sum=0;
  for(int i=0;i<N;i++){
    A.at(i)-=x;
    sum+=abs(A.at(i));
  }
  cout<<sum<<endl;

}
