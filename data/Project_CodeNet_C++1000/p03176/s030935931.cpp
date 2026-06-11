#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define int long long int
int max_query(int tree[],int start,int end,int left,int right,int index)
{
	if(left>end||start>right)
	   return 0;
	if(start>=left&&end<=right)
	   return tree[index];
	else
	{
		int mid=(start+end)/2;
		int x=max_query(tree,start,mid,left,right,2*index);
		int y=max_query(tree,mid+1,end,left,right,2*index+1);
		return max(x,y);
	}
}
void update(int tree[],int start,int end,int point,int val,int index)
{
	if(point>end||point<start)
	   return ;
	if(start==end)
	{
		tree[index]=val;
		return ;
	}
	else
	{
		int mid=(start+end)/2;
		update(tree,start,mid,point,val,2*index);
		update(tree,mid+1,end,point,val,2*index+1);
		tree[index]=max(tree[2*index],tree[2*index+1]);
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int tree[4*n+1]={0};
	int j,arr[n];
	for(j=0;j<n;j++)
	{
		cin>>arr[j];
		arr[j]--;
	}
	int arr2[n];
	for(j=0;j<n;j++)
	{
		cin>>arr2[j];
	}
	int value[n]={0};
	int answer=0;
	for(j=n-1;j>=0;j--)
	{
		int x=arr[j];
		int next=max_query(tree,0,n-1,x+1,n-1,1);
		int here=arr2[j]+next;
		value[x]=here;
		update(tree,0,n-1,x,here,1);
	}
	for(j=0;j<n;j++)
	   answer=max(answer,value[j]);
	cout<<answer<<endl;
}
