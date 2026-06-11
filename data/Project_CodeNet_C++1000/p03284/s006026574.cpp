#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	int n, k;
	cin >> n >> k;
	if(n%k == 0) cout << 0;
	else cout << 1;
}
