#include<iostream>
using namespace std;

int main() {
    int N, M, X, Y; cin >> N >> M >> X >> Y;
    int x[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    int y[M];
    for (int i = 0; i < M; i++) {
        cin >> y[i];
    }
    for (int i = X + 1; i <= Y; i++) {
        bool willStartWar = false;
        for (int j = 0; j < N; j++) {
            if (x[j] >= i) {
                willStartWar = true;
            }
        }
        for (int k = 0; k < M; k++) {
            if (y[k] < i) {
                willStartWar = true;
            }
        }
        if (!willStartWar) {
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
}
