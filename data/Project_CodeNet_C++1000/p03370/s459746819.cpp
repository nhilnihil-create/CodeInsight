#include <bits/stdc++.h>
using namespace std;

int main(){
 int n,x;
  cin>>n>>x;
  int A[1100];
  int sum=0,a=110000;
  
  for(int i=0;i<n;i++){
    cin>>A[i];
    a=min(a,A[i]);
    sum+=A[i];
  }
  
  cout<<(x-sum)/a+n<<endl;
  
}  
  