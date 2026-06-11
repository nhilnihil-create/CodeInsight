#include<bits/stdc++.h> 
using namespace std;
int main()
{
     int a[1000];
     int n=0;
     cin>>a[1]>>a[2]>>a[3];
     
     while(a[1]!=a[2]||a[2]!=a[3]||a[1]!=a[3])
     {
	 sort(a+1,a+3+1);
     	if(a[2]!=a[3]) 
     	{
     		a[1]++;
     		a[2]++;
     	}
     	else a[1]+=2;
     	n++;
     }
     cout<<n;
}

