#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long A, B, C, D;

long long gcd(long long a,long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A >> B >> C >> D;
        if (A < B || B > D) {
            cout << "No" << endl;
            continue;
        } else if (B <= C) {
            cout << "Yes" << endl;
            continue;
        }
        
        long long g = gcd(B, D);
        
//        A + k * D (mod B)で最大のものとCを比べる
        if ((A % g) + B - g > C) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}