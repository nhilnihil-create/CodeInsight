#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector <int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)

int count_bits(int n)
{
    n=(n&0x55555555)+(n>>1&0x55555555);
    n=(n&0x33333333)+(n>>2&0x33333333);
    n=(n&0x0f0f0f0f)+(n>>4&0x0f0f0f0f);
    n=(n&0x00ff00ff)+(n>>8&0x00ff00ff);
    n=(n&0x0000ffff)+(n>>16&0x0000ffff);
    return n;
}

int main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    int k[m];
    int s[m];
    REP(i, m) {
        cin >> k[i];
        s[i] = 0;
        REP(j, k[i]) {
            int tmp; cin >> tmp;
            s[i] |= (1 << (tmp-1));
        }
    }
    int p[m];
    REP(i, m) {
        cin >> p[i];
    }

    int cnt = 0;
    REP(bit, (1 << n)) {
        bool flag = true;
        REP(i, m) {
            if (count_bits(bit & s[i])%2 != p[i]) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }
    cout << cnt << "\n";
}