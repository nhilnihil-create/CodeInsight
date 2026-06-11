#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double d;

ll n,k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	if(n>=k*2-1) cout<<"YES";
	else cout<<"NO";	
	return 0;
}