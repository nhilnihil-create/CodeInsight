#include<bits/stdc++.h>//author::@whohet-->Het Patel
#define fasterthanlight ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define test int T; cin>>T; while(T--)
#define endl "\n"
#define int long long
#define vi vector<int>
#define pb push_back
#define mod 1000000007
#define MAX 1e9
#define MIN -1e9
using namespace std;

//author::@whohet-->Het Patel

signed main()
{
	fasterthanlight;
	int a, b;
	cin >> a >> b;
	if (a > 12)
		cout << b;
	else if (a <= 5)
		cout << 0;
	else
		cout << b / 2;
	return 0;
}
