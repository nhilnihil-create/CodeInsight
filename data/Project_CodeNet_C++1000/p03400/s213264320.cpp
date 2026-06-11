#include<iostream>
using namespace std;
int main()
{
	int n,d,x,i,j,a[100],sum=0;
	cin>>n>>d>>x;
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
    }
   
    for(i=0;i<n;i++)
    {
    	j=0;
    	while(j*a[i]+1<=d)
    	{
    		sum++;
    		j++;
    	}
    }
    cout<<(sum+x);

}