#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,C;
	cin>>n>>C;
	int s[100000],t[100000],c[100000];
	for(int i = 0; i<n; i++)
		cin>>s[i]>>t[i]>>c[i];
	int tt[200002]={0},st[200002]={0};
	for(int i = 1; i<=C; i++)
	{
		memset(tt,0,sizeof(tt));
		for(int j = 0; j<n; j++) 
			if(c[j] == i)
				tt[2*s[j]-1]++,tt[2*t[j]]--;
		for(int j = 1; j<200002; j++) tt[j] += tt[j-1];
		for(int j = 0 ; j<200002; j++) st[j] += (tt[j]>0);
	}
	cout<<*max_element(st,st+200002)<<endl;
	return 0;
}