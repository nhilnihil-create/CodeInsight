#include <bits/stdc++.h>
using namespace std;

int ans=1000;
int main(){
  int N;
  cin>>N;
  for (int i=0;i<N;i++){
    int A,temp=0;
    cin>>A;
    while(A%2==0){
      temp++;
      A/=2;
    }
    ans=min(ans,temp);
  }
  cout<<ans<<endl;
}