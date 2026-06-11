#include<iostream>
#include<vector>
using namespace std;
#define int long long int
#define function function2
int power[61];
void function()
{
	power[0]=1;
	int j;
	for(j=1;j<=60;j++)
	   power[j]=2*power[j-1];
}
int solve(vector<int> &arr,int k,int prev)
{
	if(arr.size()<k)
	  return 0;
	if(prev==0)
	   return 0;
	int count[61]={0};
	int j;
	for(int x:arr)
	{
		int y=x;
		for(j=60;j>=0;j--)
		{
			if(y>=power[j])
			{
				count[j]++;
				y-=power[j];
			}
		}
	}
	int ptr=-1;
	for(j=prev-1;j>=0;j--)
	{
		if(count[j]>=k)
		{
			ptr=j;
			break;
		}
	}
	if(ptr==-1)
	   return 0;
	vector<int> vec;
	for(int x:arr)
	{
		if(x&power[ptr])
		{
			vec.push_back(x);
		}
	}
	int answer=power[ptr]+solve(vec,k,ptr);
	return answer;
}
int32_t main()
{
	function();
	int n,k;
	cin>>n>>k;
	int arr[n];
	int j;
	for(j=0;j<n;j++)
	{
		cin>>arr[j];
	}
	vector<int> vec;
	for(j=0;j<n;j++)
	{
		int sum=0;
		int i;
		for(i=j;i<n;i++)
		{
			sum+=arr[i];
			vec.push_back(sum);
		}
	}
	int answer=solve(vec,k,60);
	cout<<answer<<endl;
}
