#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define MAX 200005

vector<int> seg(4*MAX, 0), ai(MAX), hei(MAX);

int query(int idx, int l, int r, int ql, int qr){
	if( l > qr || r < ql )
		return 0;
	if( ql <= l && r <= qr )
		return seg[idx];

	int md = (l+r)/2;
	return max(query(2*idx, l, md, ql, qr), query(2*idx+1, md+1, r, ql, qr));
}

void update(int idx, int l, int r, int pos, int vl){
	if( l == r ){
		seg[idx] = vl;
		return;
	}

	int md = (l+r)/2;
	if( pos <= md )
		update(2*idx, l, md, pos, vl);
	else
		update(2*idx+1, md+1, r, pos, vl);

	seg[idx] = max(seg[2*idx], seg[2*idx+1]);
}

int32_t main(){
	IOS;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> hei[i];
	for(int i = 0; i < n; i++)
		cin >> ai[i];

	for(int i = n-1; i >= 0; i--){
		int vl = query(1, 0, n, hei[i], n);
		update(1, 0, n, hei[i], vl+ai[i]);
	}

	cout << seg[1] << endl;

	return 0;
}