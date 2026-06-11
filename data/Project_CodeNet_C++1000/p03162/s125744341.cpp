#include <bits/stdc++.h>

#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back

const int maxm = 1000000000 + 7;

using namespace std;

short a[100007];
short b[100007];
short c[100007];
long long arr[100007];
long long brr[100007];
long long crr[100007];

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	loop(i, n) {
		cin >> a[i] >> b[i] >> c[i];
	}

	arr[0] = a[0];
	brr[0] = b[0];
	crr[0] = c[0];
	for (int i = 1; i < n; ++i)
	{
		/* code */
		arr[i] = a[i] + max(brr[i - 1], crr[i - 1]);
		brr[i] = b[i] + max(arr[i - 1], crr[i - 1]);
		crr[i] = c[i] + max(arr[i - 1], brr[i - 1]);
	}

	cout << max({arr[n - 1], brr[n - 1], crr[n - 1]});

}