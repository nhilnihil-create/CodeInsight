#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("YES")
#define p_no() p("NO")

template < typename T >
void vprint(T &V){
	for(auto v : V){
    	cout << v << " ";
	}
	cout << endl;
}

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll factorial(ll n){
    ll ret = 1;
    FOR(i, 1, n+1){
        ret *= i;
    }
    return ret;
}

const int N_MAX = 100010;
ll Per[N_MAX] = {}; // n!
ll Inv[N_MAX] = {}; // 1/2, 1/3, ...
ll Ac[N_MAX] = {}; // Invの累積和
 
// a^b mod p
ll mod_pow(ll a, ll b){
    if(b==0) return 1;
 
    // 肩が奇数
    if(b%2==1){
        return a * mod_pow(a, b-1) % mod;
    }
    else{
        return mod_pow(a*a % mod, b/2) % mod;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N;
    cin >> N;

    vector<ll> A(N);
    FOR(i, 0, N){
        cin >> A.at(i);
    }

    // nCr高速化準備
    Per[1] = 1;
    FOR(i, 2, N_MAX){
        Per[i] = i * Per[i-1] % mod;
    }
    Inv[1] = 1;
    FOR(i, 2, N_MAX){
        Inv[i] = mod_pow(i, 1000000005);
    }
    // 累積和
    Ac[1] = Inv[1];
    FOR(i, 2, N_MAX){
        Ac[i] = Ac[i-1] + Inv[i];
    }

    ll expectation = 0;

    FOR(i, 0, N){
        ll p = 0;
            
        // FOR(j, 0, N){
        //     ll n = abs(j-i)+1;
        //     p += Inv[n];
        //     p %= mod;
        // }

        p += Ac[N-1 - i + 1]; // 右
        p %= mod;

        p += Ac[i-0 + 1] - Ac[1]; // 左
        p %= mod;

        expectation += A[i] * p;
        expectation %= mod;
    }

    ll ans = expectation * Per[N];
    ans %= mod;
    p(ans);
    
    return 0;
}