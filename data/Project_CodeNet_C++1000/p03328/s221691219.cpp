#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int a,b,t[1000]={};
	for(int i=1;i<=999;i++)t[i]+=i+t[i-1];
	cin>>a>>b;
	cout<<t[b-a]-b<<endl;
	return 0;
}