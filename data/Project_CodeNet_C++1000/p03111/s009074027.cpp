#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<int>arr,int i,int a,int b,int c,ll sa,ll sb,ll sc)
{
	if(i==arr.size())
	{
		if(!sa||!sb||!sc)
			return INT_MAX;
		return abs(a-sa)+abs(b-sb)+abs(c-sc);
	}

	ll op1=solve(arr,i+1,a,b,c,sa,sb,sc);
	ll op2=solve(arr,i+1,a,b,c,sa+arr[i],sb,sc)+(sa?10:0);
	ll op3=solve(arr,i+1,a,b,c,sa,sb+arr[i],sc)+(sb?10:0);
	ll op4=solve(arr,i+1,a,b,c,sa,sb,sc+arr[i])+(sc?10:0);
	return min(op1,min(op2,min(op3,op4)));
}

int main()
{
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;

	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
    cout<<solve(arr,0,a,b,c,0,0,0);
}

