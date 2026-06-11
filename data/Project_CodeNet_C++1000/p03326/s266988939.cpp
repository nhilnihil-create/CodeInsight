#include<iostream>
#include<algorithm>
using namespace std;
#define int long long int
int solve(int mat[][3],int n,int m,int val1,int val2,int val3)
{
	int mat2[n][3];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			mat2[i][j]=mat[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j==0)
			{
				mat2[i][j]*=val1;
			}
			if(j==1)
			{
				mat2[i][j]*=val2;
			}
			if(j==2)
			{
				mat2[i][j]*=val3;
			}
		}
	}
	int arr[n];
	for(j=0;j<n;j++)
	{
		arr[j]=mat2[j][0]+mat2[j][1]+mat2[j][2];
		//arr[j]=abs(arr[j]);
	}
	sort(arr,arr+n);
	int answer=0;
	for(j=n-1;j>=n-m;j--)
	   answer+=arr[j];
	return answer;
}
int32_t main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	int i,j;
	int mat[n][3];
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>mat[i][j];
		}
	}
	int k;
	int answer=-100000000000000000;
	for(i=-1;i<=1;i+=2)
	{
		for(j=-1;j<=1;j+=2)
		{
			for(k=-1;k<=1;k+=2)
			{
				int val=solve(mat,n,m,i,j,k);
				answer=max(answer,val);
			}
		}
	}
	cout<<answer<<endl;
}
