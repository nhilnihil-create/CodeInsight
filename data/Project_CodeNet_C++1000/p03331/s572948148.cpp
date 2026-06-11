#include <bits/stdc++.h>//#
using namespace std;

int main() {
  int N,a,b;
  cin>>N;
  int m=N;
  int A[5]={},B[5]={};
  for(int i=1;i<N/2;i++){
    int sum=0;
    a=i;
    b=N-a;
    for (int j=0;j<5;j++){
      A[j]=a%10,a/=10;
      B[j]=b%10,b/=10;
      sum+=A[j]+B[j];
    }
    m=min(sum,m);
 	 }
	cout<<m<<endl;
}