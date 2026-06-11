#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int A, B, C, D;

map<int, char> m;


void input() {
    string s;
    cin >> s;
    A = s[0] - '0';
    B = s[1] - '0';
    C = s[2] - '0';
    D = s[3] - '0';
}


int solve(int i, int j, int k) {
    int ret = A;
    ret += pow(-1, i) * B;
    ret += pow(-1, j) * C;
    ret += pow(-1, k) * D;
    return ret;
}


void print_ans(int i, int j, int k) {
    printf("%d%c%d%c%d%c%d=7\n", A, m[i], B, m[j], C, m[k], D);
}


int main() {
    input();
    m[0] = '+';
    m[1] = '-';
    rep(i, 2) rep(j, 2) rep(k, 2) {
        int x = solve(i, j, k);
        if (x == 7) {
            print_ans(i, j, k);
            return 0;
        }
    }
}
