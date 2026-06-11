# include <iostream>
using namespace std;

long long gcd(long long B, long long D) {
    long long b = max(B, D);
    long long d = min(B, D);
    if (d == 0) {
        return b;
    } else {
        return gcd(b % d, d);
    }
}

long long is_yes(long long A, long long B, long long C, long long D) {
    
    if (B > D || B > A) {
        return false;
    }

    long long g = gcd(B, D);
    return A - ((A - (C + 1)) / g) * g - B >= 0;

}

int main() {
    int T;
    long long A, B, C, D;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> A >> B >> C >> D;

        if (is_yes(A, B, C, D)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}