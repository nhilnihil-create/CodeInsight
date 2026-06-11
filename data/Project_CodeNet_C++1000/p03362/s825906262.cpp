#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime1[60];

void make_prime()
{
	int cnt = 0;
	int n = 11;
	while(cnt <= 60)
	{
		bool flag = true;
		for (int i = 2; i*i <= n; ++i)
		{
			if (n % i == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			prime1[cnt] = n;
			cnt++;
		}
		n += 10;
	}
	return;
}

int main()
{
	make_prime();
	int N;
	cin >> N;
	rep(i,N)
	{
		if (i != 0) cout << " ";
		cout << prime1[i];
	}
	cout << endl;
	return 0;
}