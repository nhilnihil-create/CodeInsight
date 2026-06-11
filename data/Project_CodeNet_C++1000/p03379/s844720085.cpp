#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int maxn = 5e5 + 50;
typedef pair<int, int> P;

void solve();
int main()
{
	int t = 1;
//	cin >> t;
	for(int i=0; i<t; i++)
	{
		solve();
		cout << '\n';
	}
	return 0;
}

// type below

void solve()
{
	int a; cin >> a;
	int arr[a + 50], tmp[a + 50];
	for(int i=0; i<a; i++)
	{
		cin >> arr[i]; 
		tmp[i] = arr[i];
	}
	sort(tmp, tmp + a);
	for(int i=0; i<a; i++)
	{
		if(arr[i] >= tmp[a / 2]) cout << tmp[a / 2 - 1];
		else					 cout << tmp[a / 2];
		cout << '\n';
	}
}