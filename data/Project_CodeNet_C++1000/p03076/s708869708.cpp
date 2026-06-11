#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 5;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    int ans = 10;
    for(int i = 0; i < N; i++) {
        ans = min(ans, (A.at(i) - 1)%10 + 1);
    }
    for(int i = 0; i < N; i++) {
        ans += ((A.at(i) + 9)/10)*10;
    }

    cout << ans - 10 << endl;
    

    return 0;
}