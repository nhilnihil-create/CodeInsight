#include<iostream>
using namespace std;

int n;

int (*p)[3];
int (*q)[3];


int element(int (*k)[3],int i,int j)
{
	return *(*(k+i)+j);
}

int routes(int i,int c)
{	
	
	int cost0,cost1,cost2;
	
	if(c!=0)
	{
		if(i==n-1)cost0=element(p,i,0);
		else
		{
			if(element(q,i,0)!=-1)cost0=element(q,i,0);
			else {cost0=element(p,i,0)+routes(i+1,0);*(*(q+i)+0)=cost0;}
		}
		

	}
	else cost0=0;

	if(c!=1)
		{	if(i==n-1)cost1=element(p,i,1);
			else
			{
				if(element(q,i,1)!=-1)cost1=element(q,i,1);
				else{cost1=element(p,i,1)+routes(i+1,1);*(*(q+i)+1)=cost1;}
			}
			
		}
		else cost1=0;

	if(c!=2)
		{	
			if(i==n-1)cost2=element(p,i,2);
			else
			{
				if(element(q,i,2)!=-1)cost2=element(q,i,2);
				else {cost2=element(p,i,2)+routes(i+1,2);*(*(q+i)+2)=cost2;}
			}
			
		}
		else cost2=0;
	
	return max(max(cost1,cost2),cost0);
}


	
	
	
	
	

int main()
{

cin>>n;

int arr[n][3];
int arr2[n][3];
	
for(int i=0;i<n;i++)for(int j=0;j<3;j++){cin>>arr[i][j];arr2[i][j]=-1;}

p=arr;
q=arr2;

cout<<routes(0,-1);


}
