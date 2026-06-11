#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int64_t N;
    cin >> N;
    
    vector<int64_t> data(N + 1, 0);
    data[0] = 2;
    data[1] = 1;

    int64_t temp = 0;
    for (int i = 2; i < N + 1; i++) {
        temp = data[i - 1] + data[i - 2];
        data[i] = temp;
    
    }
    cout << data[N] << endl;
}