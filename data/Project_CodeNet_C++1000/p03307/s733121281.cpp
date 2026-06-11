#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int n;
	cin>>n;
	if(n==1)cout<<2<<endl;
	else if(n%2)cout<<n*2<<endl;
	else cout<<n<<endl;
	return 0;
}