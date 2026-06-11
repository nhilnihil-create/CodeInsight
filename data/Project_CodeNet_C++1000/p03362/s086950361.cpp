#include <bits/stdc++.h>
using namespace std;

bool prime(int N) {
    bool ans = true;
    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) ans = false;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    int x = 11;
    while (a.size() < N) {
        if (prime(x)) a.push_back(x);
        x = x + 10;
    }
    
    for (int i = 0; i < N - 1; ++i) cout << a[i] << " ";
    cout << a[N - 1] << endl;
    return 0;
}