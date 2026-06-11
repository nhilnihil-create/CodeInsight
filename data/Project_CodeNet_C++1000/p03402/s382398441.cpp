#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;

int A,B;
char ans[100][100];

int main ()
{
    cin >> A >> B;

    swap (A, B);

    REP(x,100) {
        REP(y,100) {
            if (x % 2) {
                ans[x][y] = '#';
            } else {
                ans[x][y] = '.';
            }
        }
        ans[x][0] = '.';
        ans[x][99] = '#';
    }

    A--;
    B--;

    for (int x = 97; A > 0; x -= 2) {
        for (int y = 2; y < 95 && A > 0; y += 2) {
            A--;
            ans[x][y] = '.';
        }
    }

    for (int x = 2; B > 0; x += 2) {
        for (int y = 97; y >= 5 && B > 0; y -= 2) {
            B--;
            ans[x][y] = '#';
        }
    }

    cout << 100 << " " << 100 << endl;
    REP(i,100) {
        REP(j,100) cout << ans[i][j];
        cout << endl;
    }

    return 0;
}
