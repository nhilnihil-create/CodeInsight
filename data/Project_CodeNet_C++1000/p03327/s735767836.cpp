#include<bits/stdc++.h>
// Begin Header {{{
#define all(x) (x).begin(), (x).end()
#define lli long long int
#define rep(i,n) for(lli i=0; i<n; i++)
#define loop(i, j, n) for(lli i=j; i<n; i++)
lli combi(lli n, lli r)
{
	if(r==0 || r==n) return 1;
	else return combi(n-1,r) + combi(n-1,r-1);
}
using namespace std;
// }}} End Header

int main()
{
	int n;
	cin >> n;
	if(n<1000) cout << "ABC" << endl;
	else cout << "ABD" << endl;
	return 0;
}
