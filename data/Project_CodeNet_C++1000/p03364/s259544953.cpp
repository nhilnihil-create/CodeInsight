#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool check = true;
        for (int j = 0; j < N; j++) {
            for (int k = j; k < N; k++) {
                if (S[(j-i+N)%N][k] != S[(k-i+N)%N][j]){
                    check = false;
                    break;
                }
            }
            if (!check)break;
        }
        if (check) ans += N;
    }
    cout << ans << endl;
    return 0;
}