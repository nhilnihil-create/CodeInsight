#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>P(N);
  for(int i=0;i<N;i++){
    cin>>P.at(i);
  }
  int price=0;
  for(int i=0;i<N;i++){
    price=max(price,P.at(i));
  }
  int halfprice=price/2;
  int ans=0;
  for(int i=0;i<N;i++){
    ans+=P.at(i);
  }
  ans=ans-price+halfprice;
  cout<<ans<<endl;
}
