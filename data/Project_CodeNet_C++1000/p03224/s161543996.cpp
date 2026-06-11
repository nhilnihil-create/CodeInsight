#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const ll INF = 1e9+7;


int main(){
	ios_base::sync_with_stdio(false);
	int N, ans=0;

	cin >> N;
	rep(i,5000){
		if( i*(i+1) / 2 == N ) ans = i+1;
	}

	int cnt = 1;
	if(ans > 0){
		vector<pii> v[100005];
		rep(i, ans) reps(j, i+1, ans){
			v[i].emplace_back(j, cnt);
			v[j].emplace_back(i, cnt);
			cnt++;
		}

		cout << "Yes" << endl;
		cout << ans << endl;
		rep(i, ans){
			cout << v[i].size();
			for(auto t: v[i]) cout << " " << t.Y;
			cout << endl;
		}
	}else{
		cout << "No" << endl;
	}

	return 0;
}