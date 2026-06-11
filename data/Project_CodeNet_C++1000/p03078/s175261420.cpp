#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<pair<LL, int> > HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int na, nb, nc, k;
LL x[N], y[N], z[N], t[N];

bool cmp(LL a, LL b)
{
	return a > b;
}

void merge(LL a[], int n, LL b[], int m)
{
	HEAP heap;
	for (int i = 0; i < m; i ++ ) heap.push({a[0] + b[i], 0});
	
	n = min(k, n * m);
	for (int i = 0; i < n; i ++ )
	{
		LL v = heap.top().F;
		int j = heap.top().S;
		heap.pop();
		
		t[i] = v;
		if (j + 1 < na) heap.push({v - a[j] + a[j + 1], j + 1});
	}
	na = n;
	memcpy(a, t, sizeof t);
}

int main()
{
	cin >> na >> nb >> nc >> k;
	for (int i = 0; i < na; i ++ ) cin >> x[i];
	for (int i = 0; i < nb; i ++ ) cin >> y[i];
	for (int i = 0; i < nc; i ++ ) cin >> z[i];
	
	sort(x, x + na, cmp);
	
	merge(x, na, y, nb);
	merge(x, na, z, nc);
	
	for (int i = 0; i < k; i ++ ) cout << x[i] << endl;
    return 0;
}