#include<iostream>
using namespace std;
int main()
{
	int n,k,count=0;
  	cin>>n>>k;
  while(n>=k)
  {
    count++;
    n--;
  }
  cout<<count;
}