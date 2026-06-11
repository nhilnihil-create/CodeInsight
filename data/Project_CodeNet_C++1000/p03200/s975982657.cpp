#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int64_t N=s.size();
  int64_t ans=0;
  int64_t w=0;
  for(int i=N-1;0<=i;i--){
  if(s.at(i)=='W')
    w++;
    else
      ans+=w;
  }cout<<ans<<endl;
    return 0;
}