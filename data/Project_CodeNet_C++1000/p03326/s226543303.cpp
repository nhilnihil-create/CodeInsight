#include<bits/stdc++.h>
using namespace std;

#define gcd(a,b)		__gcd(a,b)
#define lcm(a,b)		(a*b)/gcd(a,b)
#define ff              first
#define ss              second
#define int             long long
#define pb              emplace_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             INT_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define all(x)			x.begin(),x.end()
#define digits(x)		floor(log10(x))+1
#define FIO				ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class dsu {
private:
	int *id;
	int* sz;

	int root(int i) {
		while (i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
public:
	int n;
	dsu(int v) {
		n = v;
		id = new int[n];
		sz = new int[n];

		for (int i = 0; i < n; i++) {
			id[i] = i;
			sz[i] = 0;
		}
	}

	bool find(int p , int q) {
		return root(p) == root(q);
	}

	void join(int p , int q) {
		int i = root(p);
		int j = root(q);
		if (i == j) {
			return;
		}
		if (sz[i] < sz[j]) {
			id[i] = j ;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
	}
};

int nCr(int n , int r ) {
	int p = 1, k = 1;

	if (n - r < r ) {
		r = n - r;
	}
	if (r != 0) {
		while (r != 0) {
			p *= n ;
			k *= r ;
			int m = __gcd(p, k);
			p /= m;
			k /= m;
			n--;
			r--;
		}
	}
	else {
		p = 1;
	}
	return p ;
}

int modPower(int x, int y , int p) {
	//Used to calculate (x^y)%p
	int res = 1;
	if (y == 0) {
		return 1;
	}

	x = x % p;
	if (x == 0) {
		return 0  ;
	}

	while (y > 0) {
		if (y & 1) {
			res = (res * x) % p;
		}

		y >>= 1;
		x = (x * x) % p;
	}
	return res ;

}


int32_t main() {
	FIO;

	int n, m ;
	cin >> n >> m;

	int a[100009][3];
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			cin >> a[i][j];
		}
	}
	int val = INT_MIN;
	for (int i = 0 ; i < 8 ; i++) {
		vi v ;
		for (int j = 1 ; j <= n ; j++) {
			int s = 0 ;
			for (int k = 0 ; k < 3 ; k++) {
				if ((i / (1 << k)) % 2 == 0) {
					s += a[j][k];
				}
				else {
					s -= a[j][k];
				}
			}
			v.pb(s);
		}
		sort(all(v));
		reverse(all(v));
		int ans = 0 ;
		for (int j = 0 ; j < m ; j++) {
			ans += v[j];
		}
		val = max(val, ans);
	}




	cout << val;





	return 0;
}
