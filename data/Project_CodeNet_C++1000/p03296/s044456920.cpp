#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int b=0;
  int count=0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(a==b){
      count++;
      a=101;
    }
	b=a;
  }
	cout<<count;
}
    
