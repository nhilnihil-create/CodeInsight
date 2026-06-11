#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n, m = -2;
string res;

int main()
{
	cin >> n;
	if (!n) puts("0");
	else
	{
		for (int i = n; i; i /= m)
		{
			if (i % abs(m))
			{
				res += "1";
				if (m < 0) i -- ;
			}
			else res += "0";
		}
		reverse(res.begin(), res.end());
	}
	cout << res << endl;
    return 0;
}