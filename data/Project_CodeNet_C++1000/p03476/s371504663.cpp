#include <bits/stdc++.h>
using namespace std;
bool isPrime(int N){
    bool res = true;
    for(int i=2; i*i<=N; ++i) if (N%i==0) res = false;
    return res;
}
int main() {
    int Prime[(int)1e5+10];
    Prime[0] = Prime[1] = Prime[2] = 0;
    for (int i=3; i<=(int)1e5; i+=2) {
        Prime[i] = Prime[i-2];
        if (isPrime(i) && isPrime((i+1)/2)) Prime[i]++;
        Prime[i+1] = Prime[i];
    }
    int Q; cin >> Q;
    int l,r;
    for (int i=0; i<Q; ++i){
        cin >> l >> r;
        cout << Prime[r] - Prime[l-1] << endl;
    }
    return 0;
}