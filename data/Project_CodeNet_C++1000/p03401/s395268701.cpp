#include<iostream>
#include<cmath>
using namespace std;
#define MAXN 100000

int N;
int A[MAXN+1];

int main(){
  cin>>N;
  for(int i=1;i<=N;i++){
    cin>>A[i];
  }
  A[0]=A[N+1]=0;
  int sum=0;
  for(int i=0;i<=N;i++){
    sum+=abs(A[i]-A[i+1]);
  }
  for(int i=1;i<=N;i++){
    int s=sum;
    s=s-abs(A[i-1]-A[i])-abs(A[i]-A[i+1])+abs(A[i-1]-A[i+1]);
    cout<<s<<endl;
  }
  return 0;
}