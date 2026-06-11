#include <iostream>
#include <cstdio>
#include <vector>
#define N 200005
using namespace std;

int n, cnt, la, mx, h[N], d[N];
vector<int> a[N];
void f(int p, int q) {
	int i, t;
	cnt++;
	h[p] = h[q] + 1;
	if (h[p] > mx){
		mx = h[p];
		la = p;
	}
	for (i = 0; i < a[p].size(); i++) {
		t = a[p][i];
		if (t == q) continue;
		f(t, p);
	}
}

int main()
{
	int i, t1, t2;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &t1, &t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	f(1, 0);
	cnt = 0;
	f(la, 0);
	d[0] = 2;
	d[1] = 1;
	d[2] = 2;
	for (i = 3; i <= mx; i++) {
		if (d[i - 2] == 2 || d[i - 1] == 2) d[i] = 1;
		else d[i] = 2;
	}
	cout << (d[mx] == 1 ? "First" : "Second") << endl;
    return 0;
}
