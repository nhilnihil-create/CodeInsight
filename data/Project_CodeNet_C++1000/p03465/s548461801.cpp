#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
  int N;cin>>N;
  vi A;
  int sum=0;
  for (int i=0;i<N;++i){
    int a;cin>>a;A.push_back(a);
    sum+=a;
  }
  for (int i=0;i<N;++i){
    
  }

  bitset<2001*2001> dp;
  dp.set(0);
  for (int i=0;i<N;++i){
    dp=(dp| (dp<<A[i]));
  }

  int begin=(sum%2==0) ? sum/2 : sum/2+1;

  for (int i=begin;i<=sum;++i){
    if(dp[i]){
      cout << i << endl;
      return 0;
    }
  }
}