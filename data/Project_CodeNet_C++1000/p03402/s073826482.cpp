#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int A, B;
    cin >> A >> B;

    vector<vector<char>> gridWhite(50, vector<char>(100, '.'));
    vector<vector<char>> gridBlack(50, vector<char>(100, '#'));

    A--; B--;
    
    rep(i,50/3) rep(j,100/3) {
        if (A > 0) {
            A--;
            gridBlack[3 * i + 1][3 * j + 1] = '.';
        }
        if (B > 0) {
            B--;
            gridWhite[3 * i + 1][3 * j + 1] = '#';
        }
    }

    printf("100 100\n");
    rep(i,50) {
        rep(j,100) cout << gridWhite[i][j];
        cout << endl;
    }
    rep(i,50) {
        rep(j,100) cout << gridBlack[i][j];
        cout << endl;
    }
    
    return 0;
}