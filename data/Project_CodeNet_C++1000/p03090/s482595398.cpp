#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  cout<<(N-1)*N/2-N/2<<endl;
  if(N%2==0){
    for(int i=0;i<N;i++)
      for(int j=i+1;j<N;j++)
        if(i+j+1!=N)cout<<i+1<<' '<<j+1<<endl;
  }else{
    for(int i=0;i<N;i++)
      for(int j=i+1;j<N;j++)
        if(i+j+2!=N)cout<<i+1<<' '<<j+1<<endl;
  }
}