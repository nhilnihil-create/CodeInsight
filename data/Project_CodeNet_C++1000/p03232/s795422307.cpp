#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

int fastpow(int x, int n, int m){
    int a = 1;
    IREP(i, 64){
        a = (a * a) % m;
        if(((n >> i) & 1) == 1) a = (a * x) % m;
    }
    return a;
}

signed main(){

    int N; cin >> N;
    vec A(N); readvec(A);
    int mod = 1000000007;

    int factn = 1;
    FOR(i, 1, N + 1) factn = (factn * i) % mod;

    vec invsum(N + 1);
    FOR(i, 1, N + 1) invsum[i] = (invsum[i - 1] + fastpow(i, mod - 2, mod)) % mod;

    vec costnum(N);
    REP(i, N) costnum[i] = (invsum[i + 1] + invsum[N - i] - 1 + mod) % mod;
    int ans = 0;
    REP(i, N) ans = (ans + costnum[i] * A[i]) % mod;
    cout << (ans * factn) % mod << endl;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}