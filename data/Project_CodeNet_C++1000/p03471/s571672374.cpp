#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,Y;
  cin>>N>>Y;
  for(int i=0;i<=N;i++)
    for(int j=0;i+j<=N;j++)
      if(i*1000+j*5000+(N-i-j)*10000==Y){
        cout<<N-i-j<<' '<<j<<' '<<i<<endl;
        return 0;
      }
  puts("-1 -1 -1");
}