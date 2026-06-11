#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int> A(N),B(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    cin>>B.at(i);
  }
  vector<pair<int,int>> drink;
  for(int i=0;i<N;i++){
    drink.push_back(make_pair(A.at(i),B.at(i)));
  }
  
  sort(drink.begin(),drink.end());
  long long ans=0LL;
  
  int j=0;
  while(M!=0){
    if(drink.at(j).second==0)
      j++;
    else{
      drink.at(j).second--;
      ans+=drink.at(j).first;
      M--;
    }
  }
  cout<<ans<<endl;
}
