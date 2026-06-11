#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N, K; cin >> N >> K;

    if(K==0){
        cout << N * N << endl;
        return 0;
    }

    ll cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        int p = N/i;
        int q = N%i;
        cnt += max(0LL, i-K) * p + max(0LL, q-K+1);
    }
    cout << cnt << endl;
}