#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++);
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int A, B, C, X;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;

    int cnt = 0;
    for (int i = 0; i <= A; ++i) {
         for (int j = 0; j <= B; ++j) {
             for (int k = 0; k <= C; ++k) {
                 int total = (500*i + 100*j + 50*k);
                 if ( total == X) ++cnt; 
             }
         }
     }
     cout << cnt << endl;

}