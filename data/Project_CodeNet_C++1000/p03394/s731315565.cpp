#include <bits/stdc++.h>
using namespace std;
int a[2][8] = {{2,10,3,9,4,8,6,12}, {6,2,10,3,9,4,8,12}};

int main() {
    int N;
    cin >> N;
    if(N == 3) {
        cout << "2 5 63" << endl;
        return 0;
    } else {
        for(int i=0; i<N; ++i) {
            cout << a[N % 2][i % 8] + 12 * (i / 8) << (i == N - 1 ? '\n' : ' ');
        }
    }
}