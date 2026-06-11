#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 110;

int na, nb, nc, k;
LL a[N], b[N], t[N];

bool cmp(LL a, LL b)
{
	return a > b;
}

void merge(int nb)
{
	priority_queue<pair<LL, int> > heap;
	for (int i = 0; i < na; i ++ ) heap.push({a[i] + b[0], 0});
	
	na = min(3000, min(k, na * nb));
	for (int i = 0; i < na; i ++ )
	{
		LL v = heap.top().F;
		int j = heap.top().S;
		heap.pop();
		
		t[i] = v;
		if (j + 1 < nb) heap.push({v - b[j] + b[j + 1], j + 1});
	}
	
	memcpy(a, t, sizeof t);
}

int main()
{
	cin >> na >> nb >> nc >> k;
	
	for (int i = 0; i < na; i ++ ) cin >> a[i];
	sort(a, a + na, cmp);
	
	for (int i = 0; i < nb; i ++ ) cin >> b[i];
	sort(b, b + nb, cmp);
	merge(nb);

	for (int i = 0; i < nc; i ++ ) cin >> b[i];
	sort(b, b + nc, cmp);
	merge(nc);
	
	for (int i = 0; i < k; i ++ ) cout << a[i] << endl;
	return 0;
}