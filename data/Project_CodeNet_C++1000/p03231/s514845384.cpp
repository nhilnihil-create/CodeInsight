#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
T gcd(T a, T b){
    T n = min(a,b);
    T m = max(a,b);
    if(n == 0){ return m;}
    else {
        return gcd(n, m % n);
    }
}

int main(void)
{
    ll N, M;
    
    string S, T;

    cin >> N >> M >> S >> T;

    ll L = N * M / gcd(N, M);
    bool match = false;
    int i = 0;
    while(true){
        if(i * L/M >= N || i * L/N >= M) break;

        if(S[i * L/M] == T[i * L/N]){
            match = true;
        } else {
            match = false;
            break;
        }
        i++;
    }
    if(match){
        cout << L << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
