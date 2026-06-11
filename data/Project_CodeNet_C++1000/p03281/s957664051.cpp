#include <bits/stdc++.h>
using namespace std;

long long numberOfDivisor(long long n){
    long long cnt = 0;
    for (long long i=1; i*i <= n; ++i) {
        if (n%i==0) {
            cnt++;
            if (n/i != i) cnt++; 
        }
    }
    return cnt;
}

int main() {
    int N; cin >> N;
    int res = 0;
    for (int i=1;i<=N;i+=2) if (numberOfDivisor(i)==8) res++;
    cout << res << endl;
    return 0;
}
