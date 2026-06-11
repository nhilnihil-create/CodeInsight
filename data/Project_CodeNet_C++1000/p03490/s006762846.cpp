#include<bits/stdc++.h>
using namespace std;

int F[8005];
int A[4005][16005], B[4005][16005];

int main() {
    string s;
    int x, y;
    cin >> s;
    cin >> x >> y;
    int p = 0;    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'F') F[p]++;
        else p++;
    }
    A[0][s.size() + F[0]] = 1;
    B[0][s.size() + F[1]] = 1;
    B[0][s.size() - F[1]] = 1;
    for (int i = 1; i <= p / 2; i++) {
        for (int j = 0; j <= s.size() * 2; j++) {
            if (A[i-1][j] == 1) {
                A[i][j + F[2 * i]] = 1;
                A[i][j - F[2 * i]] = 1;
            }
            if (B[i-1][j] == 1) {
                B[i][j + F[2 * i + 1]] = 1;
                B[i][j - F[2 * i + 1]] = 1;
            }
        }
    }
    if (A[p/2][x + s.size()] == 1 && B[p/2][y + s.size()] == 1) printf("Yes\n");
    else printf("No\n");
    return 0;
}