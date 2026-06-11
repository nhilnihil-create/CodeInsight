#include<bits/stdc++.h>
#define lli long long int
using namespace std;
//469
//ar[1] = 4 , ar[2] = 6 , ar[3] = 9
int ar[20];
lli dp[20][200][2];

lli getSum(int pos , int n , lli sum , bool flag)
{
	if(pos > n) return sum;
	
	if(dp[pos][sum][flag] != -1) return dp[pos][sum][flag];
	
	int limit = 9;
	if(!flag) limit = ar[pos];
	
	lli res = 0;
	for(int i=0;i<=limit;i++)
	{
		if(flag || i != limit)
		res = max(res,getSum(pos + 1 , n , sum + i , true));
		else
		res = max(res,getSum(pos + 1 , n , sum + i , false));
//		if(pos ==1 ) cout<<res<<" ";
	}
	return dp[pos][sum][flag] = res;
}

int digitSum(string num)
{
	int res = 0;
	for(char digit : num)
	res += digit - '0';
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a;
		cin>>a;
		
		//if(a == "-1") break;
		
		lli L;
		
		//for L
		for(int i=0;i<a.size();i++)
		ar[i+1] = a[i] - '0';
		
		memset(dp , -1 , sizeof dp);
		L = getSum(1 , a.size() , 0 , 0);
		cout<<L<<endl;
}
