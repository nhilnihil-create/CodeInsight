#include<bits/stdc++.h>

using namespace std;
int main(void) {
    int N;
    cin >> N;
    int D[110];
    int max = -1;
    int min = 1000000001;
    for (int i = 0; i < N; i++) {
        cin >> D[i];
        if (D[i] < min) min = D[i];
        if (D[i] > max) max = D[i];
    }

    cout << max - min << endl;

    return 0;
}