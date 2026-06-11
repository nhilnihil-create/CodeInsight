#include<bits/stdc++.h>
using namespace std;

int main(){
  long long   n,at=-1;
  cin>>n;
  for(long long i=1;i<=n;i++){
    if(i*i<=n){
      at=max(at,i*i);
    }
  }
  cout<<at<<endl;
}
      
