#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 25; j++) {
            if(i*7+j*4 == N) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}