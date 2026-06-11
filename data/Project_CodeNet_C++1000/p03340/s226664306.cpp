#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,ans=0;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  uint32_t a=A[0];
  int b=A[0];
  for(int l=0,r=0;l<N;){
    for(r++;r<N;r++){
      a^=A[r];
      b+=A[r];
      if(a!=b){
        a^=A[r];
        b-=A[r];
        break;
      }
    }
    ans+=r-l;
    r--;
    a^=A[l];
    b-=A[l];
    if(r<=l)l++,r=l,a^=A[l],b+=A[l];
    else l++;
  }
  cout<<ans<<endl;
}