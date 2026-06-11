#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;long a=0;
  for(long i=1;i<=N;i+=2){
    long b=0;
    for(long j=1;j<=i;j++)if(i%j==0)b++;
    if(b==8)a++;
  }
  cout<<a<<endl;
  
}

