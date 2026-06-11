#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;

    for(int i = 0; i < N - 1; i++) {
        vector<bool> A(26, 0);
        int anstemp = 0;
        for(int j = 0; j < i; j++) {
            A.at(S.at(j) - 'a') = 1;
        }
        for(int j = i; j < N; j++) {
            if(A.at(S.at(j) - 'a')) {
                A.at(S.at(j) - 'a') = 0;
                anstemp++;
            }
        }
        ans = max(ans, anstemp);
    }
    cout << ans << endl;



    return 0;
}