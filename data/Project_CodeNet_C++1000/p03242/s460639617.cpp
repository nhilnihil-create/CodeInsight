#include<iostream>
using namespace std;
int main()
{
  int num;
  cin>>num;
  int rev=0;
  int sum=0,rem=0;
  while(num!=0){
 	 rem=num%10;
    num=num/10;
    if(rem==9){
    sum=sum*10+1;
    }
    else{
    sum=sum*10+9;
    }
  }
  while(sum!=0)
  {
    
    rev=(rev*10)+(sum%10);
  	sum=sum/10;
  }
  cout<<rev;
  return 0;
}