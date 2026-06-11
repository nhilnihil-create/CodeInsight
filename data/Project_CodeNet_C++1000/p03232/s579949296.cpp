#include <iostream>

#define P 1000000007

using namespace std;

long inv[100001];
long fac[100001];

void init(){
    inv[0] = 1;
    inv[1] = 1;
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i <= 100000; i++){
        inv[i] = ((-(P/i)*inv[P%i])%P +P)%P;
        fac[i] = (fac[i-1]*i)%P;
    }
}

int main(){
    int N;
    long A[100000];
    long S[100000];
    long ans = 0;
    init();
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    S[0] = 0;
    for(int i = 0; i < N; i++){
        S[0] = (S[0] + inv[i+1])%P;
    }
    for(int i = 1; i < N; i++){
        S[i] = ((S[i-1] + inv[i+1] - inv[N-i+1])%P + P)%P;
    }
    for(int i = 0; i < N; i++){
        ans = (ans+(fac[N]*((S[i]*A[i])%P)%P))%P;
    }
    cout << ans << endl;
}