#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
long long seg[4 * N], h[N], a[N];
void upd(int idx, int start, int end, int id, long long val)
{
	if (start > end || start > id || end < id)
		return;
	if (start == end)
		seg[idx] = val;
	else
	{	
		int mid = (start + end) / 2;
		upd(2 * idx + 1, start, mid, id, val);
		upd(2 * idx + 2, mid + 1, end, id, val);
		seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
	}
}
long long query(int idx, int start, int end, int l, int r)
{
	if (start > end || start > r || end < l)
		return 0;
	else if (start >= l &&  end <= r)
		return seg[idx];
	else
	{
		int mid = (start + end) / 2;
		long long lmax = query(2 * idx + 1, start, mid, l, r);
		long long rmax = query(2 * idx + 2, mid + 1, end, l, r);
		return max(lmax, rmax);
	}
}
int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
		h[i] --;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		long long mx = query(0, 0, n - 1, 0, h[i]);
		upd(0, 0, n - 1, h[i], mx + a[i]);
	}
	cout << query(0, 0, n - 1, 0, n - 1);
	return 0;
}