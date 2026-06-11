#include <iostream>

using namespace std;
int main(){
int i,n,m,c,count=0;
  cin>>n>>m>>c;
  int a[m],b[m];
  	for(i=0;i<m;i++)
    {
		cin>>b[i];
    }
  while(n--)
  {
    int s=0;
	for(i=0;i<m;i++)
    {
		cin>>a[i];
    }
    
    for(i=0;i<m;i++)
    {
		s+=a[i]*b[i];
    }
    if(s+c>0)
      count++;
  }
  cout<<count;
    return 0;
}
    
      
    