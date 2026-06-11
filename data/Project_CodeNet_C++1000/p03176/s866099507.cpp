#include<bits/stdc++.h>
#define mod (long)(1e9 + 7)
using namespace std;

long tree[8 * 100001];

void update(int start, int end, int node, int pos, long val) {
	if(start == end) {
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	if(pos <= mid) {
		update(start, mid, 2 * node, pos, val);
	}
	else update(mid + 1, end, 2 * node + 1, pos, val);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
} 

long query(int start, int end, int l, int r, int node) {
	// cout<<start << " " << end << endl;
	if(start > r || end < l) {
		return -1;
	}
	if(l <= start && end <= r) {
		// cout <<"FOr" << start <<" " << end << ":" << tree[node];
		return tree[node];
	}
	int mid = (start + end) / 2;
	long left = query(start, mid, l, r, 2 * node); 
	long right = query(mid + 1, end, l, r, 2 * node + 1);
	return max(left, right);
} 

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	long h[n], a[n];
	for(int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	update(0, n, 1, h[0], a[0]);
	for(int i = 1; i < n; ++i) {
		// cout<<tree[1000];
		long mx = query(0, n, 0, h[i] - 1, 1);
		// if(mx == -1) cout << i <<" ou";
		// break;
		// cout << mx + a[i] << endl;
		update(0, n, 1, h[i], a[i] + mx);
	}
	cout << tree[1];

	return 0;
}