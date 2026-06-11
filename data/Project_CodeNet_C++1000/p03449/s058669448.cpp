#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,candy=0,tmp=0;
  cin>>N;
  vector<int> d0(N);
  vector<int> d1(N);
  for(int i=0;i<N;i++){
    cin>>d0.at(i);
    tmp+=d0.at(i);
  }
  for(int i=0;i<N;i++){
    cin>>d1.at(i);
  }
  tmp+=d1.at(N-1);
  candy=tmp;
  for(int i=0;i<N-1;i++){
    tmp-=d0.at(N-1-i);
    tmp+=d1.at(N-2-i);
    candy=max(candy,tmp);
  }
  cout<<candy<<endl;
}