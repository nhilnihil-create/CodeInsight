#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int A[N];
  int P[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
    P[A[i]-1]=i;
  }
  int ans=1,cnt=1;
  for(int i=0;i<N-1;i++){
    if(P[i]<P[i+1]){
      cnt++;
    }
    else{
      cnt=1;
    }
    ans=max(ans,cnt);
  }
  /*int cnt2=1;
  for(int i=N-1;i>=1;i--){
    if(P[i]>P[i-1]){
      cnt2++;
    }
    else break;
  }*/
  cout<<N-ans<<endl;
  return 0;
}

  