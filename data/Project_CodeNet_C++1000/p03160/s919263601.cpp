#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int> H(N);
  for(int i=0;i<N;i++) cin>>H.at(i);
  vector<int> dp(N);
  dp.at(0)=0;
  dp.at(1)=abs(H.at(0)-H.at(1));
  for(int i=2;i<N;i++){
    int X=dp.at(i-1)+abs(H.at(i-1)-H.at(i));
    int Y=dp.at(i-2)+abs(H.at(i-2)-H.at(i));
    dp.at(i)=(X>Y?Y:X);
  }
  cout<<dp.at(N-1)<<endl;
}