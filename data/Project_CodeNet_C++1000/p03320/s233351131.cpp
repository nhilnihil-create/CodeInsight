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

	vector<pair<double,ll>> st;
	for(ll i=1; i<=1e15; i++){
		ll sum = 0, cur = i, cnt = 0;
		while(cur){
			sum += cur % 10;
			cur /= 10;
			cnt++;
		}
		double score = (double)i/(double)sum;
		while( st.size() && st.back().X > score ) st.pop_back();
		st.emplace_back(score, i);
		if( cnt > 2 ){
			ll add = 1, cur = i;
			rep(j, cnt){
				if( cur%10 != 9 || j >= cnt - 4 ){
					i += add - 1;
					break;
				}
				cur /= 10;
				add *= 10;
			}
		}
	}
	//for(auto t: st){
	//	cout << t.Y << "\t" << t.X << endl;
	//}
	rep(i,N) cout << st[i].Y << endl;

	//rep(i,N){
	//	if( i<9 ) cout << i+1 << endl;
	//	else{
	//		cout << 1;
	//		rep(j,i-8) cout << 9;
	//		cout << endl;
	//	}
	//}

	return 0;
}