#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int &i:A)
    cin>>i;
  vector<bool> B(N,true);
  vector<int> C(0);
  for(int i=N;i>0;i--){
    bool bo=true;
    for(int j=0,k=0;k<i;j++){
      if(!B[N-j-1])
        continue;
      if(A[N-j-1]==i-k){
        C.push_back(i-k);
        B[N-j-1]=false;
        bo=false;
        break;
      }
      k++;
    }
    if(bo){
      puts("-1");
      return 0;
    }
  }
  for(int i=N-1;i>=0;i--)
    cout<<C[i]<<endl;
}