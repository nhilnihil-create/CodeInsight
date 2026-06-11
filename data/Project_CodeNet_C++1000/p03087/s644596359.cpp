#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;

int N,Q,i,j,q[100001];
char S[100001];

int main(void){
  cin >> N >> Q;
  cin >> S;
  int a[Q],b[Q], cnt=0;
  for(i=0;i<Q;i++){
    cin >> a[i] >> b[i];
  }
  q[0]=0;
  if(S[0]=='A'){
    cnt = 1;
  }
  for(i=1;i<N;i++){
    if(S[i]=='A'){
      cnt=1;
      q[i]=q[i-1];
    }else if(S[i]=='C' && cnt==1){
      q[i]=q[i-1]+1;
      cnt=0;
    }else{
      cnt=0;
      q[i]=q[i-1];
    }
  }
  for(i=0;i<Q;i++){
    printf("%d\n",q[b[i]-1]-q[a[i]-1]);
  }
  return 0;
}
