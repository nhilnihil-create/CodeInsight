#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a, i, c=0, odd=0;
    cin >> N;
    int t[N];


    for(i=0; i<N; i++) {
        cin >> a;
        t[i] = a;
    }
    while (!odd) {
        for (i=0; i<N; i++) {
            if (t[i]%2 != 0) {
                odd++;
                break;
            }
            t[i] /=2;
        }
        c++;
    }
    cout << c-1 << endl;
}