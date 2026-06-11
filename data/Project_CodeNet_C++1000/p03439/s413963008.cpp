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

int main() {
    int n;
    cin >> n;

    cout << 0 << endl << flush;
    string s0;
    cin >> s0;
    if (s0[0] == 'V') return 0;

    int l = 0, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        cout << m << endl << flush;
        
        string s;
        cin >> s;
        if (s[0] == 'V') return 0;
        else if (s0 == s) {
            if (m % 2 == l % 2) {
                l = m;
                s0 = s;
            }
            else r = m;
        }
        else {
            if (m % 2 != l % 2) {
                l = m;
                s0 = s;
            }
            else r = m;
        }

    }
  	return 0;

}
