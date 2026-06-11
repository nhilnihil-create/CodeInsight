#include<iostream>

using namespace std;

int main(void)
{
  int a,b; cin>>a>>b;
  int count=0;
  int b_max=30;
  
  for(int i=1;i<=a;i++){
    if(i==a){b_max=b;}
    for(int j=1;j<=b_max;j++){
      if(i==j){count++;}
    }
  }
  
  cout<<count<<endl;
  return 0;
}