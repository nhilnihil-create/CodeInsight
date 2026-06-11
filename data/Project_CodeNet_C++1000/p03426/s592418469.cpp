#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,D,temp,ans;
  cin>>H>>W>>D;
  int d[90001];
  vector<pair<int,int>>A(90001);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>temp;
      A[temp].first=i;
      A[temp].second=j;
    }
  }
  
  for ( int i = D +1; i <= H * W ; i ++){
    d[ i ]= d [i - D ]+ abs(A[i].first-A[i-D].first)+abs(A[i].second-A[i-D].second);
  }

  int Q,L,R;
  cin>>Q;

  for(int i=0;i<Q;i++){
    ans=0;
    cin>>L>>R;
    if(L==R){
      cout<<0<<endl;
      continue;
    }
    ans=d[R]-d[L];
    cout<<ans<<endl;
  }
  
  return 0;
}

