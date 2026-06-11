#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int next(int n)
{
	n++;
	int res  = n;

	int add = 1;
	while(n)
	{
		if(n%10==4)
		{
		res -= add*4;
		res += add*10;
		n+=10;
		}
		add*=10;
		n/=10;
	}
	return res;
}
int ten(int n)
{
	int res = 1;
	for(int i = 0;i<n;i++)
	{
		res*=10;
	}
	return res;
}


int main()
{
	int n;
	cin >> n;
	int tn = ten(n);
	int bit = 0;
	int A[4];
	cin >> A[1] >> A[2] >> A[3];
	vector<int> l(n);
	for(int i =0 ;i<n;i++)
	{
		cin >> l[i];
	}
	int  ans = 1001001001;
	for(int i = 0;bit<tn;i++)
	{
		//cout<<bit<<endl;
		bit = next(bit);

		int B = bit;
		int cnt[4]={};
		int add[4]={};
		int j = 0;
		while(B)
		{
			add[B%10]+=l[j++];
			cnt[B%10]++;
			B/=10;
		}
		int cost = 0;
		for(int i = 1;i<=3;i++)
		{
			if(cnt[i]==0)cost= 1e9;
			cost += 10*max(0,cnt[i]-1);
			cost += abs(add[i]-A[i]);
		}
		ans = min(ans,cost);
		//if(cost==120)cout<<bit<<endl;
	}
	cout<<ans<<endl;
}