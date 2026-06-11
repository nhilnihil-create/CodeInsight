#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<bool>P(100001,1);P[0]=0;P[1]=0;
  for(long i=2;i<=100000;i++)if(P[i]){
    for(long j=2;i*j<=100000;j++)P[i*j]=0;
  }
  vector<long>C(100001);
  for(long i=3;i<=100000;i+=2){
    C[i]=C[i-2]+P[i]*P[(i+1)/2];
  }
  long q;cin>>q;
  for(long i=0;i<q;i++){
    long l,r;cin>>l>>r;
    cout<<C[r]-(l>1?C[l-2]:0)<<endl;
  }
}