#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A,B,C,K;
  long long ans;
  cin>>A>>B>>C>>K;
  if(K%2==1){
    ans=B-A;
  }
  else ans=A-B;
  if(ans>1000000000000000000){
    cout<<"Unfair"<<endl;
    return 0;
  }
  cout<<setprecision(19)<<ans<<endl;
}

  