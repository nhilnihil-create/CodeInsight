#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{

	int n,k; cin >> n >> k;
	vector<int> a(n);
	int mini = 100001;
	int ite;
	rep(i, n)
	{
		cin >> a[i];
		if (a[i] == 1)
			ite = i;
	}
	if (n <= k)
	{
		cout << 1; return 0;
	}

	int cnt = 0;

	if (ite % (k - 1) == 0)
		cnt += ite / (k - 1);
	else
	{
		cnt += ite / (k - 1) ;
		cnt++;
	}
	n--;
	if (ite+1 >=  k)
	{
		if(ite % (k - 1) == 1)
		{
			if ((n - ite - 1) % (k - 1) == 0)
				cnt += (n - ite) / (k-1);
			else
			{
				cnt += (n - ite) / (k-1);
				cnt++;
			}
		}
		else if ((n - ite) % (k - 1) == 0)
			cnt += (n - ite) / (k-1);
		else
		{
			cnt += (n - ite) / (k-1);
			cnt++;
		}
	}
	else
	{
		if (ite == 0)
			cnt++;
		if ((n - k - 1) % k == 0 )
			cnt += (n - k - 1) / (k-1);
		else
		{
			cnt += (n - k - 1) / (k-1);
			cnt++;
		}
	}
	cout << cnt << endl;
	// cout << ite << endl;
	return (0);
}
