#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    string S;
    cin >> S;


    S = "Z" + S + "ZZZ";
    string T;
    REP(i,0,SZ(S)-2) {
        if(S.substr(i, 3) == "ABC") {
            T += "X";
            i += 2;
        }
        else if(S.substr(i, 2) == "BC") {
            T += "Y";
            ++i;
        }
        else T += S[i];
    }

    string P = T, Q = T;
    REP(i,0,SZ(P)) {
        if(P[i] == 'X' || i == 0) {
            ll r = i + 1;
            while(P[r] == 'Y' && P[r] != 'Z') ++r;
            while(P[r] != 'X' && P[r] != 'Z') {
                P[r] = 'Z';
                ++r;
            }
        }
    }
    REP(i,0,SZ(Q)) {
        if(P[i] == 'X' || i == SZ(Q) - 1) {
            ll l = i - 1;
            while(Q[l] == 'A' && Q[l] != 'Z') --l;
            while(Q[l] != 'X' && Q[l] != 'Z') {
                Q[l] = 'Z';
                --l;
            }
        }
    }
    REP(i,0,SZ(P)) P[i] = MIN(P[i],Q[i]);
    P = P.substr(1,SZ(P)-1);

    vector<string> R;
    string U;
    bool f = true;
    REP(i,0,SZ(P)) {
        if(P[i] == 'Z' && f) {
            R.pb(U);
            U = "";
            f = false;
        }
        else if(P[i] != 'Z'){
            if(P[i] == 'X') U += "AY";
            else U += P[i];
            f = true;
        }
    }
    
    ll cnt = 0;
    FORR(u,R) {
        ll c = 0;
        REP(i,0,SZ(u)) {
            if(u[i] == 'Y') {
                cnt += i - c;
                ++c;
            }
        }
    }
    PR(cnt);

    return 0;
}

/*



*/