#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1000000000000000000;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll N;
char field[610][610];

int main(){
    cin >> N;
    rep(i,N) rep(j,N) cin >> field[i][j];
    rep(i,N*2) rep(j,N*2) field[i][j] = field[i%N][j%N];
    ll ans = 0;
    rep(i,N){
        rep(j,N){
            rep(k,N){
                if(field[i+j][k] != field[i+k][j]) goto ES;
            }
        }
        ans++;
        ES:;
    }
    cout << ans * N << endl;
}
