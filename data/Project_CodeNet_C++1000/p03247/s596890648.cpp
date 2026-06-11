#include <iostream>

using namespace std;

typedef long long ll;

int N;
int M=35;
ll X[1005];
ll Y[1005];

int main() {
        cin >> N;
        for (int i=0; i<N; i++)
                cin >> X[i] >> Y[i];

        bool seen_parity[2] = {false,false};
        for (int i=0; i<N; i++) {
                seen_parity[(X[i]+Y[i])%2] = true;
        }

        if (seen_parity[0] && seen_parity[1]) {
                cout << "-1\n";
                return 0;
        }

        if (seen_parity[0])
                cout << M+1 << "\n1\n";
        else
                cout << M << "\n";

        for (int i=M-1; i>=0; i--)
                cout << (1ll << i) << "\n";

        for (int i=0; i<N; i++) {
                if (seen_parity[0]) {
                        cout << "R";
                        X[i]--;
                }
                for (int j=M-1; j>=0; j--) {
                        if (X[i] > Y[i] && X[i] > -Y[i]) {
                                cout << "R";
                                X[i] -= (1ll << j);
                        } else if (Y[i] > X[i] && Y[i] > -X[i]) {
                                cout << "U";
                                Y[i] -= (1ll << j);
                        } else if (-X[i] > Y[i] && -X[i] > -Y[i]) {
                                cout << "L";
                                X[i] += (1ll << j);
                        } else {
                                cout << "D";
                                Y[i] += (1ll << j);
                        }
                }

                cout << "\n";
        }
}