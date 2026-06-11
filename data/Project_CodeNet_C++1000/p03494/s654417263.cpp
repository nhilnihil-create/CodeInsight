#include <bits/stdc++.h>
using namespace std;

int ans=1000;
int main(){
  int N,A[200];
  cin>>N;
  for (int i=0;i<N;i++){
    int A,temp=0;
    cin>>A;
    if (A%2==1){
      ans=0;
      break;
    }
    while(A%2==0){
      temp++;
      A/=2;
    }
    if(temp<ans) ans=temp;
    temp=0;
  }
  cout<<ans<<endl;
}
  