#include <iostream>

using namespace std;

int main() {
  int ans,n,s;
  int i=1;
  cin>>n;
  if(n==1 || n==2 ||n==4)
    ans=4;
  else
  {  
    while(n!=4)
  {
	if(n%2==0){
      n=n/2; i++;
    }
    else{
      
      n=(3*n)+1; i++;
    }
	ans=i+3;
  }
  }
  cout<<ans;
  
  return 0;
}
  