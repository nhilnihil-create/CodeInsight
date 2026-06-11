#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

bool is_integer( double x ){
    return std::floor(x)==x;
}

int main() {
    ll N,M;
    cin >> N >> M;

    string S,T;
    cin >> S;
    cin >> T;

    REP(j, M) {
        double i = (double)N/M*j;

        if (is_integer(i)) {
            if (S[i] != T[j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    ll lcm = N*M/gcd(N,M);
    cout << lcm << endl;

    return 0;
}
