/*
ID: tohoast1
TASK: gymnastics
LANG: C++
*/
#include <bits/stdc++.h>
#define speedup ios_base::sync_with_stdio(NULL)
#define fin freopen("gymnastics.in", "r", stdin)
#define fout freopen("gymnastics.out", "w", stdout)
#define FILENAME
#define PUBG push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define cls clear
#define INF const int ci = 1e6 + 100
#define K_INF 1e9 + 7
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define MIN_INT -999999999
#define MOD 1000000007
#define d109 1000000000

using namespace std;
typedef long long LL;
typedef long L;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef string STR;
double n, k, abd;

int main() {
    #ifdef FILENAMEs
        fin;
        fout;
    #endif // FILENAME
    cin >> n >> k;
    if (round(n / 2) >= k) cout << "YES";
    else cout << "NO";
    ///time;
    return 0;
}
