#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,Q;
  string S;
  cin>>N>>S>>Q;
  vector<int> K(Q);
  for(int i=0;i<Q;i++){
    cin>>K[i];
  }
  for(int q=0;q<Q;q++){
    long long D=0,M=0,C=0;
    long long A=0;
    for(int i=0;i<N;i++){
      if(S[i]=='D'){
        D++;
      }else if(S[i]=='M'){
        M++;
        C+=D;
      }else if(S[i]=='C'){
        A+=C;
      }
      if(i>=(K[q]-1)){
        if(S[i-K[q]+1]=='D'){
          D--;
          C-=M;
        }else if(S[i-K[q]+1]=='M'){
          M--;
        }
      }
    }
    cout<<A<<"\n";
  }
}