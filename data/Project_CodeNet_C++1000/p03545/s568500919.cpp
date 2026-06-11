#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    string S; cin >> S;
    int s = stoi(S);
    int A = (s / 1000) % 10, B = (s / 100) % 10, C = (s / 10) % 10, D = s % 10;
    vector<int> X(4);
    X[0] = A; X[1] = B; X[2] = C; X[3] = D;
    int sum;
    for(int bit = 0; bit < (1 << 3); bit++) {
        sum = X[0];
        bitset<3> b(bit);
        for(int i = 0; i < 3; i++) {
            if(b.test(i)) sum += X[i + 1];
            else sum -= X[i + 1];
        }
        if(sum == 7) {
            for(int i = 0; i < 4; i++) {
                if(i == 0) {
                    cout << X[0];
                    if(b.test(i)) cout << '+';
                    else cout << '-';
                }
                else if(i != 3) {
                    cout << X[i];
                    if(b.test(i)) cout << '+';
                    else cout << '-';
                }
                else cout << X[3] << '=' << 7 << endl;
            }
            break;
        }
    }
    return 0;
}