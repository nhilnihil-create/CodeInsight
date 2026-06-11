#include <iostream>

using namespace std;

long long int GCD(long long int x, long long int y) {
    if(x<y) swap(x, y);
    if(y==0) return x;
    return GCD(y, x%y);
}

long long int LCM(long long int x, long long int y) {
    return x/GCD(x, y)*y;
}

int main() {
    long long int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    
    long long int gcd=GCD(N, M), lcm;
    lcm = M/gcd*N/gcd;
    bool flag=true;
    for(long long int i=1; i<=N/gcd*M/lcm; i++) {
        long long int n=(i-1)*lcm*gcd/M, m=(i-1)*lcm*gcd/N;
        if(S[n]!=T[m]) {
            flag=false;
            break;
        }
    }
    if(flag) {
        cout << N/gcd*M << endl;
    } else {
        cout << -1 << endl;
    }


    return 0;
    
}