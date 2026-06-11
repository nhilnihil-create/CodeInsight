#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int N,Q;
  cin>>N>>S>>Q;
  for(int i=0;i<Q;i++){
    int k;
    cin>>k;
    int64_t D=0,M=0,dm=0,Z=0;
    for(int i=0;i<N;i++){
      if(i-k>=0){
        if(S[i-k]=='M'){
          M--;
        }
        if(S[i-k]=='D'){
          D--;
          dm-=M;
        }
      }
      if(S[i]=='D'){
        D++;
      }
      if(S[i]=='M'){
        M++;
        dm+=D;
      }
      if(S[i]=='C'){
        Z+=dm;
      }
    }
    cout<<Z<<endl;
  }
}

