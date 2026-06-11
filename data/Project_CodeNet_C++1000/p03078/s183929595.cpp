#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	ll x, y, z, k; 
	cin >> x >> y >> z >> k;
	vector<ll> a(x), b(y), c(z);
	rep(i,x) cin >> a[i];
	rep(i,y) cin >> b[i];
	rep(i,z) cin >> c[i];

	// aとbの組なら全列挙出来る
	vector<ll> ab(0);
	rep(i,x){
		rep(j,y){
			ab.push_back(a[i]+b[j]);
		}
	}
	sort(ab.begin(),ab.end());
	int n = ab.size();

	// abにaとbの和が昇順に入っているがそこからどうしたらいいんだ
	// 各Ciにおける最大値を優先度付きキューにぶちこむ
	priority_queue<pair<ll,int>> pque;
	rep(i,z){
		pque.push({ab[n-1]+c[i], n-1});
	}

	while(k--){
		auto X = pque.top();
		pque.pop();
		ll sum, ind_ab;
		sum = X.first;
		ind_ab = X.second;
		cout << sum << endl;
		sum -= ab[ind_ab];
		if(ind_ab!=0){
			ind_ab--;
			sum += ab[ind_ab];
			pque.push({sum, ind_ab});
		}
	}
}
