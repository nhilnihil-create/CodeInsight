#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    ll G = gcd(N, M);
    bool check = true;
    for (int i = 0; i < G; i++) {
        if (S[N/G*i] != T[M/G*i]) check = false;
    }
    if (check) cout << N*M/G << endl;
    else cout << -1 << endl;
    return 0;
}