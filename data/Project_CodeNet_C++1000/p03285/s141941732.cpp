#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i <= 25; i++) {
        for (int j = 0; j <= 15; j++) {
            if (i*4 + j*7 == N) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}