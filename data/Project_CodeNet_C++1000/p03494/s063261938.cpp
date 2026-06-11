#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int A;
  int n;
  int ans;
  for(int i=0;i<N;i++){
    n=0;
    cin>>A;
    for(int j=0;A%2==0;j++){
      A/=2;
      n++;
    }
    if(i==0){
      ans=n;
    }
    if(i>0){
      if(ans>n){
        ans=n;
      }
    }
  }
  cout<<ans<<endl;
}
