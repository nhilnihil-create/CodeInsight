#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if(x == 2) return true;
    if(x < 2 || x % 2 == 0) return false;

    for(int i=3; i*i<=x; i=i+2) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    int N; cin >> N;
    int cur = 2;
    while(N > 0) {
        while(cur % 5 != 2 || !isPrime(cur)) ++cur;
        cout << cur << (N==1 ? '\n' : ' ');
        ++cur;
        --N;
    }
}