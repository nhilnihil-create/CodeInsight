#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{

	int n,m,a,b;
	cin>>n>>m;
	cin>>a>>b;
	cout<<n*m-min(a,b)*min(a,b)-a*(m-min(a,b))-b*(n-min(a,b))<<endl;
	return 0;
}