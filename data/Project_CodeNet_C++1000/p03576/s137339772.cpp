#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)	for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,s,n)	for(int i=(s), i##_len=(n); i<i##_len; ++i)

#define ALL(obj)	(obj).begin(),(obj).end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define VEC vector

typedef unsigned int 			uint;
typedef unsigned long long int	ull;
typedef long long int 			ll;

typedef pair<int,int>			P;
typedef vector<int>				Vint;
typedef vector<Vint>			VV;

template<typename T>string join(const v(T)&v)
{stringstream s;REP(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define MAX 		400010

const ll LINF = (ll)9e18+7;		//
const int INF = 100100100;			//2,147,483,647 (Max int)
const ll MOD = 1e9+7;
// テンプレ終了
//====================================================================//

// int DP[MAX];

//
int main(){
	int N,K;cin >> N >> K;
	VEC<ll> x(N),y(N), X(N),Y(N);
	REP(i,N){cin>>X[i]>>Y[i];
		x[i]=X[i],y[i]=Y[i];
	}

	sort(ALL(X));
	sort(ALL(Y));

	ll ans = (ll)(X[N-1]-X[0])*(Y[N-1]-Y[0]);

	REP(xl,N){
		REPS(xr,xl+1,N){
			REP(yd,N){
				REPS(yu,yd+1,N){
					int cnt = 0;
					REP(itr,N){
						if(X[xl]<=x[itr]&&x[itr]<=X[xr]&&Y[yd]<=y[itr]&&y[itr]<=Y[yu])cnt++;
					}
					if(cnt>=K)ans = min(ans,( (ll)(X[xr]-X[xl])*(Y[yu]-Y[yd]) ) );
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}


