#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxn = 16;
const ll oo = 1ll<<50;
ll memo[(1<<maxn)];
ll costo[1<<maxn];
int A[maxn][maxn],N;
int idx[1000000],cnt1;
ll fin;

ll dp(int mask){
	if(mask == fin)return 0;
	ll &res = memo[mask];
	if(res != -oo)return res;
	int cnt11 = 0;
	forn(i,0,N)if(!(mask&(1<<i))){
		idx[cnt1++] = i;
		cnt11++;
	}
	res = -oo;
	forn(i,1,(1<<(cnt11))){
		int newMask = mask;
		int mascaraAgarrados = 0;
		forn(j,0,cnt11){
			if(i&(1<<j)){
				newMask |= (1<<idx[cnt1-cnt11+j]);
				mascaraAgarrados |= (1<<idx[cnt1-cnt11+j]);
			}
		}
		ll tmp = costo[mascaraAgarrados];
		res = max(res,tmp+dp(newMask));		
	}
	cnt1 -= cnt11;
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,0,(1<<maxn))memo[i] = -oo;
	cin >> N;
	forn(i,0,N)forn(j,0,N)cin >> A[i][j];
	forn(i,0,1<<N){
		vi agarrados;
		forn(j,0,N){
			if(i&(1<<j)){
				agarrados.pb(j);
			}		
		}
		forn(j,0,(int)agarrados.size()){
			forn(k,j+1,(int)agarrados.size()){
				int a1 = agarrados[j];
				int a2 = agarrados[k];
				costo[i] += A[a1][a2];
			}
		}
	}
	fin = (1<<N)-1;
	ll res = dp(0);
	cout << res << '\n';
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
