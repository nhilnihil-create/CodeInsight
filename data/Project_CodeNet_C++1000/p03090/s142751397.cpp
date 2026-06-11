#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    if (N % 2 == 0) {
        cout << N*(N-2)/2 << endl;
        for (int i = 1; i <= N-1; i++) {
            for (int j = i+1; j <= N; j++) {
                if (i+j==N+1) continue;
                cout << i << " " << j << endl;
            }
        }
        return 0;
    }
    else if (N % 2 == 1) {
        cout << (N*(N-2)+1)/2 << endl;
        for (int i = 1; i <= N-1; i++) {
            for (int j = i+1; j <= N; j++) {
                if (i+j==N) continue;
                cout << i << " " << j << endl;
            }
        }
        return 0;
    }
    return 0;
}