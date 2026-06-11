#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll A,B;cin>>A>>B;
	if(A%2==0)
	{
		if((B-A+1) % 4 == 0)cout<<0;
		else if((B-A+1) % 4 == 1)cout<<B;
		else if((B-A+1) % 2 == 0)cout<<1;
		else cout<<(B ^ 1);
	}
	else
	{
		if((B-A) % 4 == 0)cout<<A;
		else if((B-A) % 4 == 1)cout<<(A ^ B);
		else if((B-A) % 2 == 0)cout<<(A ^ 1);
		else cout<<(A ^ (B ^ 1));
	}
}