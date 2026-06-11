#include<iostream>

using namespace std;

int main(void)
{
  long long int i,n; cin>>n;
  
  for(i=1;i<=n;i++){
    if((i*i)>n){break;}
  }
  
  cout<<(i-1)*(i-1)<<endl;
  return 0;
}