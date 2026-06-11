#include<bits/stdc++.h>

#define INF 1000010000
#define nl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define sz(c) (c).size()
#define rep(i,n) for( int i = 0; i < n; ++i )
#define repi(i,n) for( int i = 1 ; i <= n; ++i )
#define repn(i,n) for( int i = n - 1 ; i >= 0 ; --i )
#define repf(j,i,n) for( int j = i ; j < n ; ++j )
#define die(s) {std::cout << s << nl;}
#define dier(s) {std::cout << s; return 0;}
#define dbg(var) {std::cout << #var << "  = " << var << nl;}
#define vi vector<int>
typedef long long ll;

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	int n;
	cin >> n;
	
	vi v(n);
	rep(i , n){
		cin >> v[i];
	}
	
	SORT(v);
	
	int l = 0 , r = n - 2;
	while(r - l > 1){
		int mid = (r + l) / 2;
		if(2 * v[mid] <= v[n - 1]){
			l = mid;
		}else{
			r = mid;
		}
	}

	if(r != n - 1){
		if(abs(2 * v[r] - v[n - 1]) < abs(2 * v[l] - v[n - 1])){
			l = r;
		}
	}
	
	cout << v[n - 1] << " " << v[l] << endl;

	return 0;
}
