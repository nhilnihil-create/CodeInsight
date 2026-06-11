#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
// #ifndef ONLINE_JUDGE
//        // for getting input from input.txt
//        freopen("input.txt", "r", stdin);
//        // for writing output to output.txt
//        freopen("output.txt", "w", stdout);
// #endif
	int n,d,x,t=0;
	cin>>n>>d>>x;
	vector<int> v(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	for (int i = 0; i < n; ++i)
	{
		/* code */
		t = t + (1+ (d-1)/v[i]);
	}
	cout<<t+x<<endl;
	return 0;
}