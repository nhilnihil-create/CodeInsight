#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  cin>>n;
  if(n==1){ cout<<"1"; return 0; }
  for(int i=1;i<=n;i++){
    if(i*i>n){
      cout<<(i-1)*(i-1);
      return 0;
    }
  }

}
