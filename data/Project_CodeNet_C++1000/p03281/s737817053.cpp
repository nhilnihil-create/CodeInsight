#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int c=0;
  for(int i=1;i<=n;i++){
    int d=0;
    for(int j=1;j<=i;j++){
      if(i%j==0){
        if(j==2)
          break;
        else
          d++;
      }
    }
    if(d==8)
      c++;
  }
  cout<<c<<endl;
}