#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
/*----------------------------------------------------------------------------------*/

int main() {
    int a, b; cin >> a >> b;
    vector<vector<char>> ans(100, vector<char>(100));
    rep(i,100) rep(j,100) {
        if (i < 50) ans[i][j] = '#';
        else ans[i][j] = '.';
    }

    a--; b--;
    for (int i = 0; i < 50; i+=2) {
        for (int j = 0; j < 100; j+=2) {
            if (a) {
                ans[i][j] = '.';
                a--;
            }
        }
    }
    for (int i = 51; i < 100; i+=2) {
        for (int j = 0; j < 100; j+=2) {
            if (b) {
                ans[i][j] = '#';
                b--;
            }
        }
    }

    printf("100 100\n");
    rep(i,100) {
        rep(j,100) {
            printf("%c", ans[i][j]);
        }
        cout << endl;
    }
    return 0;
}
