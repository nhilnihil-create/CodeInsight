#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    long long int M, A, R, C, H;
    M = 0;
    A = 0;
    R = 0;
    C = 0;
    H = 0;

    for (int i = 0; i < N; i++) {
        switch (S[i][0]) {
            case 'M':
                M++;
                break;
            case 'A':
                A++;
                break;
            case 'R':
                R++;
                break;
            case 'C':
                C++;
                break;
            case 'H':
                H++;
                break;
        }
    }

    long long int count = 0;

    count += M * A * R;
    count += M * A * C;
    count += M * A * H;
    count += M * R * C;
    count += M * R * H;
    count += M * C * H;
    count += A * R * C;
    count += A * R * H;
    count += A * C * H;
    count += R * C * H;

    cout << count << endl;

    return 0;
}
