#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, res, i_d, j_d, k_d;
    res = 0;

    cin >> A >> B >> C >> X;

    for (int i = 0; i <= A; i++){
        for (int j = 0; j <= B; j++){
            for (int k = 0; k <= C; k++){
                if (500 * i + 100 * j + 50 * k == X){
                    res += 1;
                }
            }
        }
    }
    
    cout << res << endl;
}