#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

int n;
char s[305][305];

bool check(int p, int q) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[(p + i) % n][(q + j) % n] != s[(p + j) % n][(q + i) % n])
                return false;
        }
    }
    return true;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> s[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += check(i, 0) * n;
    }
    cout << ans << endl;

}