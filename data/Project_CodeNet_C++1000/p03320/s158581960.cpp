#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000009
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-10
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 100005

int n;

ll cal(ll x){
	ll res = 0;
	while(x){
		res += (x % 10);
		x /= 10;
	}
	return res;
}

int main(){
	srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//	freopen("in.txt", "r", stdin);
    ll run = 1, add = 1;
    cin >> n;
    Rep(i, n){
    	cout << run << endl;
    	run += add;
    	while(1){
    		ll x = run + add;
			if(run * cal(x) <= x * cal(run)){
//				cout << run << endl;
				break;
			} else {
				run += add * 9;
				add *= 10;
			}
    	}
    }

    return 0;
}
