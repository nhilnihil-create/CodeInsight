#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) {}
#endif



ll n, k;

struct sushi{
	ll t;
	ll d;
};

int main(){
	cin >> n >> k;
	vector<sushi> v(n);
	set<int> types;
	rep(i,n){
		int t, d;
		cin >> t >> d;
		v[i].t = t;
		v[i].d = d;
		types.insert(t);
	}
	
	sort(v.begin(),v.end(),[](const sushi &l, const sushi &r){
		return l.d > r.d;
	});
	
	vector<sushi> v1, v2; // v1: そのタイプの中で最も大きいもの v2: それ以外
	rep(i,n){
		if ( types.count(v[i].t) ){
			types.erase(v[i].t);
			v1.push_back(v[i]);
		}
		else{
			v2.push_back(v[i]);
		}
	}
	
	
	ll from_v1 = min( (int)k, SZ(v1) );
	ll from_v2 = k - from_v1;
	
	ll score = 0;
	rep(i,from_v1)
		score += v1[i].d;
	rep(i,from_v2)
		score += v2[i].d;
	ll max_score = score + from_v1*from_v1;
	eprintf( "v1:%lld v2:%lld max=%lld %lld\n", from_v1, from_v2, max_score, score + from_v1*from_v1 );
	
	while ( from_v1 > 0 && from_v2 < SZ(v2) ){
		from_v1--;
		score -= v1[from_v1].d;
		score += v2[from_v2].d;
		from_v2++;
		eprintf( "v1:%lld v2:%lld max=%lld %lld\n", from_v1, from_v2, max_score, score + from_v1*from_v1 );
		chmax( max_score, score + from_v1*from_v1 );
	}
	
	cout << max_score << endl;
	
	
	return 0;
}


