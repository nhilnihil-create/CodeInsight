#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using lli=long long int;
using ld=long double;

lli N;
lli memo[1001][10001];

struct element
{
	lli w;
	lli s;
	lli v;
	lli w_plus_s;
};

element arr[1001];

bool compare(element i,element j)
{
	return(i.w_plus_s > j.w_plus_s);
}



lli max_value(lli index,lli wt)
{
	if(wt>10000)
		return 0;
	if(index==-1)
		return 0;
	if(memo[index][wt]!=-1)return memo[index][wt];
	if(wt>arr[index].s)
		return ( memo[index][wt] = max_value(index-1,wt) );
	return( memo[index][wt] =   max( max_value(index-1,wt) , max_value(index-1,wt+arr[index].w)+arr[index].v )   );
}


int main()
{
	lli i,j;
	for(i=0;i<=1000;i++)
		for(j=0;j<=10000;j++)
			memo[i][j]=-1;


	cin>>N;

	for(i=0;i<N;i++)
	{
		cin>>arr[i].w>>arr[i].s>>arr[i].v;
		arr[i].w_plus_s=arr[i].w + arr[i].s;
	}
	sort(arr,arr+N,compare);


	lli ans=max_value(N-1,0);
	cout<<ans;
	return 0;
}
