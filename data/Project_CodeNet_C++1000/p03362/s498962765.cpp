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

int n;

bool is_prime(int x)
{
	if (x < 2) return false;
	if (x == 2) return true;
	for (int i = 2; i <= x / i; i ++ )
		if (x % i == 0)
			return false;
	return true;
}

int main()
{
	cin >> n;
	for (int i = 2; i; i ++ )
		if (i % 5 == 1 && is_prime(i))
		{
			cout << i << ' ';
			if ( -- n == 0) return 0;
		}
    return 0;
}