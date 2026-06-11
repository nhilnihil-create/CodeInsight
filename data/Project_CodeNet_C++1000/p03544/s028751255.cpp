#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  scanf("%d",&N);
  vector<int64_t> luka(N+1,0LL);
  luka.at(0)=2LL;
  luka.at(1)=1LL;
  for(int i=0;i<N-1;i++){
    luka.at(i+2)=luka.at(i)+luka.at(i+1);
  }
  printf("%ld",luka.at(N));
}