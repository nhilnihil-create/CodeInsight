#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    if (N == 1 || N == 2 || N == 4) {
        cout << 4 << endl;
    }
    else {
        int i = 1;
        while(true) {
            if (N%2 == 1) {
                N = 3*N + 1;
            }
            else {
                N /= 2;
            }
            i++;
            if (N == 4) {
                cout << i + 3 << endl;
                break;
            }
        }
    }
    
}
