#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> b;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    int total = 0;
    for (int i = 0; i < N; i++) {
        int sum = 0; 
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            sum += b[j] * x;
        }
        if ((sum + C) > 0) {
            total++;
        }
    }
    cout << total << endl;
    return 0;
}