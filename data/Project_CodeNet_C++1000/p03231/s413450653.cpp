#include <iostream>
using namespace std;
typedef long long ll;

ll calc_gcd(ll a, ll b) {
    if(b==0) return a;
    return calc_gcd(b, a%b);
}


bool possible(ll a, ll b, string S, string T) {
    ll gcd = calc_gcd(a, b);
    int indexS = 0, indexT = 0;
    ll intervalS = a/gcd, intervalT = b/gcd;

    bool flag = true;
    while((indexS + intervalS)<=a && (indexT + intervalT)<=b) {
        if(S[indexS]!=T[indexT]) {
            flag = false;
            break;
        }
        indexS += intervalS;
        indexT += intervalT;
    }
    return flag;
}

ll solve(ll N, ll M, string S, string T) {
    ll lcm = -1;
    if(possible(N, M, S, T)) {
        lcm = (N*M)/calc_gcd(N, M);
    }
    return lcm;
}

int main() {
    ll N, M;
    string S, T;

    cin >> N >> M >> S >> T;

    cout << solve(N, M, S, T) << endl;
}