#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n,sum=0,k;
	cin>>n;	
	k=n;
	while(n>0){
		sum+=n%10;
		n=n/10;
	}

	if(k%sum==0) cout<<"Yes"; else cout<<"No";

   return 0;
}
