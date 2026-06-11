#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N, Y;
    cin >> N >> Y;
    for (int i=0; i<N+1; i++) {
        for (int j=0; j<N-i+1; j++) {
            if (10000*i+5000*j+1000*(N-i-j)==Y) {
                cout << i << " " << j << " " << N-i-j << endl;
                exit(0);
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}