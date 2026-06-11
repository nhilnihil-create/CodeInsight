#include<bits/stdc++.h>
#include <string> 

using namespace std;
long long X,N;
int A[2000010]{};

int main()
{
  cin>>N;
  bool flag =true;
  int count=0;
  for(;0<=N;){
    if(N<10)break;
    if(N%10!=9)flag=false;
    count++;
    N/=10;
  }
  count*=9;
  if(flag)count++;
  count+=N-1;
  cout<<count;
  return 0;
}



