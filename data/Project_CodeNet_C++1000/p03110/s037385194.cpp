#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
int main() 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		float x;cin>>x;
		string u;cin>>u;
		if(u=="JPY")s+=x;
		else s+=x*380000;
	}
	cout<<s;
}