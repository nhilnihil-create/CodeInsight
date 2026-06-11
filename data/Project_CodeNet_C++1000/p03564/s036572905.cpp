#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, x=1;
    cin >> N >> K;

    for (int i=0; i<N; i++) {
        x = (x*2 <= x+K ? x*2: x+K);
    }
    cout << x << endl;
}
