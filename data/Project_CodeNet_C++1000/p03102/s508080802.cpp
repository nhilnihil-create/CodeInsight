#include<iostream>
#include<string>
using namespace std;
int main(){

    long int a[20][20],b[20],i,j,n,m,c,count=0;long int sum;
    
    cin>>n>>m>>c;
    
    for(i=0;i<m;i++)
    cin>>b[i];
    
    for(i=0;i<n;i++)
     for(j=0;j<m;j++)
       {cin>>sum;a[i][j] = sum*b[j];}
     
    for(i=0;i<n;i++){
		sum=c;
		for(j=0;j<m;j++)
		 sum+=a[i][j];
		 
		if(sum>0)count++;
		 
	}
	cout<<count;
    
 }



