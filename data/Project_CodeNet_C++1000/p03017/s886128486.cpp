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

void solve() {
    int N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    string s;
    cin >> s;
    int len = 0;
    FOR(i,A-1,C) {
        if (s[i] == '#') len++;
        else len = 0;
        if (len == 2) {
            cout << "No" << endl;
            exit(0);
        }
    }

    len = 0;
    FOR(i,B-1,D+1) {
        if (s[i] == '#') len++;
        else len = 0;
        if (len == 2) {
            cout << "No" << endl;
            exit(0);
        }
    }

    if (C>D) {
        len = 0;
        FOR(i,B-2,D+1) {
            if (s[i] == '.') len++;
            else len = 0;
            if (len == 3) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
        cout << "No" << endl;
        exit(0);
    }

    cout << "Yes" << endl;

}

int main() {
    solve();
    return 0;
}
