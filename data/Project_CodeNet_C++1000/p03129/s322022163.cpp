#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int n,k;
	cin>>n>>k;
	if(n%2&&k<=n/2+1)cout<<"YES"<<endl;
	else if(n%2==0&&k<=n/2)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
	