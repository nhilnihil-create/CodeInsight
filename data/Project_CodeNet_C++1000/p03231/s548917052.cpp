#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b)
{
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}


int main(){
    ll N, M;
    cin >> N >> M;
    ll L = gcd(N,M);
    string S,T;
    cin >> S >> T;

    bool flag = true;

    N /= L;
    M /= L;

    rep(i,L) {
        if(S[i*N] != T[i*M]) flag=false;
    }

    if(flag){
        cout << N*M*L << endl;
    }
    else{
        cout << -1 << endl;
    }

}