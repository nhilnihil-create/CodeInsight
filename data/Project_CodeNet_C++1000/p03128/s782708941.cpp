#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
	#define W(x, y) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << y;
#else
	#define W(x, y)
#endif


#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pi acos(-1)
#define ld long double
#define prime (1000000000 + 7)

using namespace std;

#define INF 1000000000

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    ll n, m;
	cin >> n >> m;

	map<ll, ll> mapa;

	vl vet{0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	vll vet2;
	for(int i = 1; i <= m; ++i){
		ll  a;
		cin >> a;
		vet2.push_back({a, vet[a]});
	}
	ll o = vet2.size();
	
	vector<pair<pll, ll>> mat(n+1);
	for(int i = 0; i < o; ++i){
		mat[vet2[i].ss] = max(mat[vet2[i].ss], {{1, vet2[i].ff}, 0});
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < o; ++j){
			if(i - vet2[j].ss >= 0 && mat[i - vet2[j].ss].ff.ff != 0){
				mat[i] = max(mat[i], {{mat[i - vet2[j].ss].ff.ff+1, vet2[j].ff}, i - vet2[j].ss});
			}
		}
	}

	string s;
	pair<pll, ll> u{mat.back()};
	while (u.ff.ff != 0){
		W(u.ff.ff, " | ");
		s.push_back(u.ff.ss + '0');
		u = mat[u.ss];
	}
	cerr << endl;
	W(u.ff.ss, endl);
	W(s.size(), endl);
	
	
	cout << s << endl;
	



	return 0;
}