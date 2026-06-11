#include<bits/stdc++.h>
using namespace std;
int main() {
    int N, Y;
    cin >> N >> Y;
    int man = -1;
    int gosen = -1;
    int sen = -1;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            int k = N - i - j;
                if (i+j+k == N && 1000*k + 5000*j + 10000*i == Y && k >= 0) {
                    man = i;
                    gosen = j;
                    sen = k;
                }
        }
    }

    cout << man << " " << gosen << " " << sen << endl;
}