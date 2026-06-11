#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  
  int wk1=1,wk2=1;
  if(n==1){
    int input;
    cin>>input;
    if(input%2==0)
      cout<<1<<endl;
    else
      cout<<2<<endl;
  }
  else{
    for(int i=0;i<n;i++){
      int input;
      cin>>input;
      wk1*=3;
      if(input%2==0){
       wk2*=2;
      }else{
        wk2*=1;
      }
    }
    cout<<wk1-wk2<<endl;;
  }

  return 0;
}