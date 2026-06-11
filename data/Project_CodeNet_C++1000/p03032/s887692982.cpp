#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=ll>
T in(){ T x; cin >> x; return (x); }
template<typename T=ll,typename C=vector<T>>
C vecin(int N){ C x(N);REP(i,N){ x[i]=in<T>(); }return move(x); }

void vout(){ cout << endl; }
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){ cout << ' ' << h;vout(forward<Tail>(t)...); }
void out(){ cout << endl; }
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){ cout << h;vout(forward<Tail>(t)...); }

template<typename T>
bool chmax(T& a,T b){ if(a<b){ a=b;return true; }return false; }
template<typename T>
bool chmin(T& a,T b){ if(a>b){ a=b;return true; }return false; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	auto N=in(),K=in();
	auto V=vecin(N);
	
	ll maxV=0;
	REP(i,min(K+1,N+1)){
		// i個取り出す内、左からl個、右からi-l個取る
		for(int l=0;l<=i;l++){
			ll C=0;
			priority_queue<ll,vector<ll>,greater<ll>> Q;
			for(int j=0;j<l;j++){
				Q.push(V[j]);
				C += V[j];
			}
			for(int j=0;j<i-l;j++){
				Q.push(V[N-1-j]);
				C += V[N-1-j];
			}
			maxV = max(maxV,C);
			// K-i回まで不要なものを捨てる
			for(int k=0;k<K-i && !Q.empty();k++){
				ll X = Q.top();
				Q.pop();
				C -= X;
				maxV = max(maxV,C);
			}
		}
	}
	out(maxV);
	return 0;
}
