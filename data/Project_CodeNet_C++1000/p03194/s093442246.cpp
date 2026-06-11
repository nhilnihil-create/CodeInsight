#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef pair<int , int> i_i;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<ll>> ve_vel;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) *max_element(all(a))
#define minel(a) *min_element(all(a))
#define acc accumulate
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

ll beki(ll a, ll n){
    if(n == 0){
        return 1;
    }
    ll ans = beki(a, n / 2);
    ans = ans * ans;
    if(n % 2 == 1) ans = ans * a;
    return ans;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    ll N,P; cin >> N >> P;

    if(N == 1) {cout << P << endl; return 0;}
    if(N >= 41) {cout << 1 << endl; return 0;}
    if(P == 1) {cout << 1 << endl; return 0;}

    ll ans = 1;
    for(ll i = 1; beki(i,N) <= P; i++){
        ll c = beki(i,N);
        if(P % c == 0) ans = i;
    }
    cout << ans << endl;
    return 0;
}