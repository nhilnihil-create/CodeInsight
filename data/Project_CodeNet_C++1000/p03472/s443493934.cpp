#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  int N;
  long long H;
  cin>>N>>H;
  long long a[100000],b[1000000];
  long long M=0;
  for(int i=0;i<N;i++){
    cin>>a[i]>>b[i];
    if(a[i]>M) M=a[i];
  }
  sort(b,b+N);
  long long answer=0;
  int j=N-1;
  while(H>0&&j>=0&&b[j]>M){
    H-=b[j];
    answer++;
    j--;
  }
  if(H>0) answer+=(H+M-1)/M;
  cout<<answer<<endl;
  
  return 0;
}