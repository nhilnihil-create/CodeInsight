#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    double ave = 0;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        ave += (double)A[i];
    }
    
    ave /= (double)N;
    
    double dis = 1000;
    int ans = -1;
    for (int i = 0; i < N; i++) {
        double res = ave-A[i]; if (res < 0) res *= (-1);
        if (res < dis) { ans = i; dis = res; }
    }
    
    cout << ans << endl;
    return 0;
}