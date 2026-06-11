#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,T,A,minK=1e9+7,P=-1;
  cin >> N >> T >> A;
  for(int i=0;i<N;i++){
    int H;
    cin >> H;
    int K=abs(1000*A-1000*T+H*6);
    if(minK>=K){
      minK=K;
      P=i+1;
    }
  }
  cout << P << endl;
}