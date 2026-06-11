#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<string> board1(n), board2(n);
    rep(i, n) {
        cin >> board1[i];
    }

    int cnt = 0;
    rep(a, n) {

        rep(i, n) {
            board2[i] = board1[(i+a)%n];
        }

        int flag = 0;
        rep(i, n-1) {
            for(int j = i+1; j < n; j++) {

                if(board2[i][j] != board2[j][i]) {
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }

        if(!flag) {
            cnt++;
        }
    }

    cout <<n*cnt << endl;
    return 0;
}