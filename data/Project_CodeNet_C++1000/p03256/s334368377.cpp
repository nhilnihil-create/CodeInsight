#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template < typename T >
void vprint(T &v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	ll N, M;
	cin >> N >> M;
	string S;
	cin >> S;
	vector<ll> G[201010];
	REP(i, M){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<ll> A(201010, 0), B(201010, 0);
	REP(i, N){
		REP(j, G[i].size()){
			if(S[G[i][j]]=='A') A[i]++;
			else B[i]++;
		}
	}
	queue<ll> bad;
	vector<ll> badis(201010, 0);
	REP(i, N){
		if(A[i]<1||B[i]<1) bad.push(i), badis[i]=1;
	}
	while(!bad.empty()){
		ll now = bad.front();
		bad.pop();
		REP(i, G[now].size()){
			ll next = G[now][i];
			if(S[now]=='A') A[next]--;
			else B[next]--;
			if((A[next]<1||B[next]<1)&&badis[next]==0) bad.push(next), badis[next]=1;
		}
	}
	ll res = 0;
	REP(i, N) if(badis[i]==1) res++;
	cout << (res==N?"No":"Yes") << endl;
    return 0;
}