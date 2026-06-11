#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t X,Y;
  cin>>X>>Y;
  int64_t x=Y/X;
  int64_t sum=1;
  int ans=0;
  for(int i=0;sum<=x;i++){
  ans++; sum*=2;
  }cout<<ans<<endl;
   return 0;
  
}

