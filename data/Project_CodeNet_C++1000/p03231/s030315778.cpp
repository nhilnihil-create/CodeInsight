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

    ll L;
    bool match = false;
    if(N%M != 0 && M%N != 0){
        L = M*N / gcd(N, M);
        int i = 0;
        while(true){
            if(i * L/M >= N || i * L/ N >= M) break;

            if(S[i * L/M] == T[i * L/N]){
                match = true;
            } else {
                match = false;
                break;
            }
            i++;
        }

    } else {
        L = max(M, N);

        int step = max(M,N) / min(M,N);

        for(int i = 0; i < min(M,N); i++){
            if(M > N){
                if(S[i] == T[i*step]) match = true;
                else {
                    match = false;
                    break;
                }
            } else {
                if(S[i*step] == T[i]) match = true;
                else {
                    match = false;
                    break;
                }
            }
        }
    }

    if(match){
        cout << L << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
