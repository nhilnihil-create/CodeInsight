#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long mod = 1000000007;
int N;
vector<ll> A;
vector<ll> B;
vector<ll> C;
vector<ll> D;
vector<ll> sumA;
vector<ll> sumB;
vector<ll> sumC;
vector<ll> sumD;

vector<ll> get_sumvec(vector<ll> a){
    vector<ll> sumvec(N+1, 0);
    for(int i=N-1; i>=0; i--){
        sumvec[i] = sumvec[i+1] + a[i];
    }
    return sumvec;
}

int solve(
    bool isAq,
    bool isBq,
    bool isCq
){
    vector<ll> BC(N, 0);
    for(int i=0; i<N; i++){
        auto b = isBq? D[i] : B[i];
        auto c = isCq? sumD[i+1] : sumC[i+1];
        BC[i] = (b * c) % mod;
    }
    auto sumBC = get_sumvec(BC);

    vector<ll> ABC(N, 0);
    for(int i=0; i<N; i++){
        auto a = isAq? D[i] : A[i];
        auto bc = sumBC[i+1];
        ABC[i] = (a * bc) % mod;
    }
    ll res = 0;
    for(int i=0; i<N; i++){
        res += ABC[i];
        res %= mod;
    }
    return res;
}

int main()
{
    string S;
    cin >> S;
    N = S.size();
    A = vector<ll>(N, 0);
    B = vector<ll>(N, 0);
    C = vector<ll>(N, 0);
    D = vector<ll>(N, 0);
    for(int i=0; i<N; i++){
        if     (S[i]=='A') A[i]++;
        else if(S[i]=='B') B[i]++;
        else if(S[i]=='C') C[i]++;
        else if(S[i]=='?') D[i]++;
    }
    sumA = get_sumvec(A);
    sumB = get_sumvec(B);
    sumC = get_sumvec(C);
    sumD = get_sumvec(D);
    int Q = sumD[0];
    long long powQ0 = 1;
    long long powQ1 = 1;
    long long powQ2 = 1;
    long long powQ3 = 1;
    for(int i=0; i<Q; i++){
        powQ0 *= 3;
        powQ0 %= mod;
        if(i==0) continue;
        powQ1 *= 3;
        powQ1 %= mod;
        if(i==1) continue;
        powQ2 *= 3;
        powQ2 %= mod;
        if(i==2) continue;
        powQ3 *= 3;
        powQ3 %= mod;
    }
    ll res = 0;
    res += solve(false, false, false) * powQ0;
    res %= mod;
    if(Q>=1){
        res += solve(false, false,  true) * powQ1;
        res += solve(false,  true, false) * powQ1;
        res += solve( true, false, false) * powQ1;
        res %= mod;
    }
    if(Q>=2){
        res += solve(false,  true,  true) * powQ2;
        res += solve( true,  true, false) * powQ2;
        res += solve( true, false,  true) * powQ2;
        res %= mod;
    }
    if(Q>=3){
        res += solve(true, true, true) * powQ3;
        res %= mod;
    }
    cout << res << endl;

    return 0;
}
