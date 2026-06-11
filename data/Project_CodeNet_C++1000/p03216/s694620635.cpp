#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int i=0; i<n; i++)
#define REP2(i, a, b) for(int i=a; i<b; i++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1'000'000'007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

void inc(long long &d, long long &m, long long &dm, long long &dmc, char c){
    switch(c){
        case 'D':
            d++;
            break;
        case 'M':
            m++;
            dm += d;
            break;
        case 'C':
            dmc += dm;
            break;
    }
}
void dec(long long &d, long long &m, long long &dm, long long &dmc, char c){
    switch(c){
        case 'D':
            d--;
            dm -= m;
            break;
        case 'M':
            m--;
            break;
    }
}

long long solve(long long N, string S, long long k){
    long long d = 0;
    long long m = 0;
    long long dm = 0;
    long long dmc = 0;
    for(long long i=0; i<k; i++){
        inc(d, m, dm, dmc, S[i]);
    }
    for(long long i=k; i<N; i++){
        dec(d, m, dm, dmc, S[i-k]);
        inc(d, m, dm, dmc, S[i]);
    }
    return dmc;
}

int main(){
    long long N, Q;
    string S;
    cin >> N >> S >> Q;
    vector<long long> K(Q);
    REP(i, Q) cin >> K[i];
    REP(i, Q)
        cout << solve(N, S, K[i]) << endl;
    return 0;
}
