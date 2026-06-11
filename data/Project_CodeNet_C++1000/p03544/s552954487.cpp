#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int main (){
  int N;
  cin>>N;
  vector<int64_t> sum(87);
  sum[0]=2;
  sum[1]=1;
  for(int i=2;i<=N;i++){
    sum[i]=sum[i-1]+sum[i-2];
  }
  cout<<sum[N]<<endl;
}
