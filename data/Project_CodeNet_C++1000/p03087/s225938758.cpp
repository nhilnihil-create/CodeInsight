#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,Q;
  string S;
  cin>>N>>Q>>S;
  
  vector<int64_t> vecL(Q);
  vector<int64_t> vecR(Q);
  for(int i=0;i<Q;i++){
    cin>>vecL.at(i)>>vecR.at(i);
  }
  vector<int64_t> rui(N);
  int64_t kai=0;
  rui.at(0)=0;
  for(int i=1;i<N;i++){
    if(S.at(i)=='C'&&S.at(i-1)=='A') kai++;
    rui.at(i)=kai;
  }
  for(int i=0;i<Q;i++){
    cout<<rui.at(vecR.at(i)-1)-rui.at(vecL.at(i)-1)<<endl;
      
  }
  
  
}