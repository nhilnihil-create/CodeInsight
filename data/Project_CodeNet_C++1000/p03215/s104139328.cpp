#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 3e18+7
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;

vector<ll> sum_list;

ll bit_count(ll a){
    ll ret = 0;
    for(ll x : sum_list){
        if((x & a) == a) ret++;
    }
    return ret;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    REP(i,N) cin >> a[i];
    
    REP(i,N){
        ll sum = 0;
        for(int j=i;j<N;j++){
            sum += a[j];
            if(sum != 0) sum_list.push_back(sum);
        }
    }
    
    ll mask = 0;
    for(ll i=40;i>=0;i--){
        if(bit_count(mask | (1LL<<i)) >= K) mask |= (1LL << i);
    }
    cout << mask << endl;
}