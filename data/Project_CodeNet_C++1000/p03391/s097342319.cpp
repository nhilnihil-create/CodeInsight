#include<bits/stdc++.h>
using namespace std;
static const int64_t INF=10000000000;
int main(){
int N;
  cin>>N;
  int64_t sum=0; int64_t MIN=INF;
  for(int i=0;i<N;i++){
  int64_t a,b; cin>>a>>b;
   sum+=a;
    if(b<a){if(b<MIN) MIN=b;}
  }if( MIN==INF)
    cout<<0<<endl;
  else{
  cout<<sum-MIN<<endl;
  }
   return 0;
}