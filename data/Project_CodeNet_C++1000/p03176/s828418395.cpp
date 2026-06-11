#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

struct SegmentTree{
	int x;
	std::vector<ll> data;

	SegmentTree(int n){
		x = 1;
		while(x < n){
			x *= 2;
		}
		data = std::vector<ll>(x*2-1);
	}

	void update(int i, ll value){
		i += x - 1;
		data[i] = value;
		while(i > 0){
			i = (i-1) / 2;
			data[i] = std::max(data[i*2+1], data[i*2+2]);
		}
	}

	ll _query(int a, int b, int i, int l, int r){
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return data[i];
		ll v1 = _query(a, b, i*2+1, l, (l+r)/2);
		ll v2 = _query(a, b, i*2+2, (l+r)/2, r);
		return std::max(v1, v2);
	}
	ll query(int a, int b){
		return _query(a, b, 0, 0, x);
	}
};

int main(){
	int n;
	std::cin >> n;
	std::vector<int> h(n);
	std::vector<ll> a(n);
	for(int i=0; i<n; i++){
		std::cin >> h[i];
	}
	for(int i=0; i<n; i++){
		std::cin >> a[i];
	}

	SegmentTree seg(n+1);
	for(int i=0; i<n; i++){
		seg.update(h[i], seg.query(0, h[i]) + a[i]);
	}
	std::cout << seg.query(0, n+1) << std::endl;
	return 0;

}