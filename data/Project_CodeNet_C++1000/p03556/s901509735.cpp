#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll n;
	cin>>n;
	ll i=0;
	while(i*i<=n){
		i++;
	}	
	cout<<(i-1)*(i-1);

   return 0;
}
