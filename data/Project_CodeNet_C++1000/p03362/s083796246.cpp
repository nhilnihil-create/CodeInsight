#include <bits/stdc++.h>
using namespace std;

vector<pair<long long,int>> f(long long N){
  vector<pair<long long ,int>> ans(1,{0,0});
  long long n=N;
  for(int i=2;i<=sqrt(n);i++){
    if(N%i==0){
      N/=i;
      if(ans.at(ans.size()-1).first==i){
        ans.at(ans.size()-1).second++;
      }
      else{
        ans.push_back({i,1});
      }
      i--;
    }
    if(N==1){
      break;
    }
  }
  if(N!=1){
    ans.push_back({N,1});
  }
  auto itr1=ans.begin();
  ans.erase(itr1);
  return ans;
}

int main() {
  long long N,c=0,i=2;
  cin>>N;
  while(c<N){
    if(f(i).at(0).first==i&&i%5==1){
      cout<<i<<" ";
      c++;
    }
    i++;
  }
  
}
