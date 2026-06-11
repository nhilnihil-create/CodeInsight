#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int res = 0;
    for(int i=0; i<N-K+1; i++) {
        res++;
    }

    cout << res << endl;
    return 0;
}
