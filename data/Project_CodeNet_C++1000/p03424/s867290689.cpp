#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  int A[4];
  rep(i,4)A[i]=0;
  rep(i,N){
    char H;
    cin>>H;
    if(H=='G')A[0]+=1;
    if(H=='W')A[1]+=1;
    if(H=='P')A[2]+=1;
    if(H=='Y')A[3]+=1;
  }
  int ans=0;
  rep(i,4){
    if(A[i]>0)ans+=1;
  }
  if(ans==4)cout<<"Four"<<endl;
  else cout<<"Three"<<endl;
  return 0;
}