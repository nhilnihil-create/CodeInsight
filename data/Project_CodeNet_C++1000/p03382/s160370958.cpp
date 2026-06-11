#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

pair<int , int> res;

int a[maxn] , n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a , a + n);

	int k = lower_bound(a , a + n , a[n - 1] / 2) - a;

	if(k)
	{
		double t = a[n - 1] / 2;

		if(fabs(a[k] - t) > fabs(a[k - 1] - t) || k == n - 1)
			k--;
	}

	cout << a[n - 1] << " " << a[k] << endl;

}





