#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N; cin >>N;
  int count=0;
  int countA=0;
  int countB=0;
  int countAB=0;
  for(int i=0;i<N;i++){
    string A;
    cin>>A;
    int kazu=A.size();
    if(A[0]=='B'&&A[kazu-1]=='A'){
      countAB++;
    }else if(A[kazu-1]=='A'){
      countB++;
    }else if(A[0]=='B'){
      countA++;
    }
    for(int j=0;j<kazu-1;j++)if(A[j]=='A'&&A[j+1]=='B')count++;
  }
  int kotae=0;
  if(countAB==0){
    kotae=min(countA,countB);
  }else{
    if(countA+countB==0){
      kotae=countAB-1;
    }else{
      kotae=countAB+min(countA,countB);
    }
  }
  kotae+=count;
  cout <<kotae<<endl;
}