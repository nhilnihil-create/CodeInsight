#include "iostream"
using namespace std;
int main()
{
  bool y=true;
  int a[5];
  int k;
  for(int i=0;i<5;i++){
    cin>>a[i];
  }
  cin>>k;
  for(int i=4;i>=1;i--){
    for(int j=i-1;j>=0;j--){
      if((a[i]-a[j])<=k){
        
        continue;
      }
      else{
        y=false;
        break;

      }
    }

    if(y==false){
      break;
    }
  }
  if(y==true){
    cout<<"Yay!"<<endl;

  }
  else{
    cout<<":("<<endl;
  }
}
