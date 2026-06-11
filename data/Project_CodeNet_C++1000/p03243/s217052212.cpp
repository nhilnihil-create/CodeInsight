#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    while (true) {
        if (N%111 == 0) {
            break;
        }
        N++;
    }
    cout << N << endl;
}

