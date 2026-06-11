#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    string S; cin >> S;
    long long W = 0, B = 0;
    for (long long i = 0; i < N; i++) {
        if (S.at(i) == '.') W++;
    }
    long long ans = W;
    for (long long i = 0; i < N; i++) {
        if (S.at(i) == '#') B++;
        else if (S.at(i) == '.') W--;
        long long num = B + W;
        if (ans > num) ans = num;
    }
    cout << ans << endl;
}