#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  scanf("%d",&N);
  
  vector<int64_t> L(90);
  L.at(0)=2LL;
  L.at(1)=1LL;
  for(int i=2;i<=N;i++){
    L.at(i)=L.at(i-1)+L.at(i-2);
  }
  printf("%lld\n",L.at(N));
}