#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ull gcd(ull a, ull b){
    if(a < b) swap(a, b);

    if(b == 0)
        return a;
    else 
        return gcd(b, a%b);
}

int solve(ull a, ull b, ull c, ull d){
    if(a < b) return -1;
    if(d < b) return -1;
    if(b <= c) return 1;

    ull g = gcd(b, d);
    ull M = b - g + (a % g);
    if(M > c)
        return -1;
    else
        return 1;
}

int main(){
    int T;
    cin >> T;

    REP(t,T){
        ull A, B, C, D;
        cin >> A >> B >> C >> D;
        int valid = solve(A, B, C, D);
        if(valid == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
