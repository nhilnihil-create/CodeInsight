#include <iostream>
using namespace std;

int main()
{
  int N,A;
  cin>>N;
  cin>>A;
  if(1<=N<=10000&&0<=A<=1000)
    {
      if(N%500<=A)
	{
	  cout<<"Yes"<<endl;    
	}
      else
	{
	  cout<<"No"<<endl;
	}      
    }
  
}
