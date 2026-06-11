#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

typedef long long int_type;
const int MAX_N = 1005;
int_type base = 1007;
int_type mod = 1000000007;
vector<int_type> pow1(MAX_N,1);
void pow_init() {
    for(int i=1;i<MAX_N;++i) {
        pow1[i] = pow1[i-1] * base % mod;
    }
}

struct RollingHash {

    vector<int_type> hash;

    RollingHash(){}

    void init(const string &s) {
        int n=s.size();
        hash.assign(n+1,0);
        for (int i=0;i<n;++i) {
            hash[i+1] = (hash[i]+s[i]) * base % mod;
        }
    }

    int_type get(int l, int r) {
        int_type t = (hash[r] - hash[l] * pow1[r-l] % mod + mod) % mod;
        return t; 
    }

};

int main() {
    pow_init();
    int N; cin >> N;
    vector<string> S(2*N);
    REP(i,N) cin >> S[i];
    REP(i,N) S[i] = S[i] + S[i];
    REP(i,N) S[i+N] = S[i];
    vector<string> T(2*N);
    REP(i,2*N)REP(j,2*N) T[i] += S[j][i];
    vector<RollingHash> yoko(2*N);
    vector<RollingHash> tate(2*N);
    REP(i,2*N) yoko[i].init(S[i]);
    REP(i,2*N) tate[i].init(T[i]);
    int ans = 0;
    REP(i,N)REP(j,N){
        bool flag = true;
        REP(k,N) if(yoko[i+k].get(j,j+N)!=tate[j+k].get(i,i+N)) flag = false;
        if(flag) ans ++;
    }
    cout << ans << endl;
    return 0;
}