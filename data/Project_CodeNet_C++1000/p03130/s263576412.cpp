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
int a1, b1, a2, b2, a3, b3, ch1, ch2, ch3, ch4, h1, h2;
vector <int> vc;

int main() {
    #ifdef FILENAMEs
        fin;
        fout;
    #endif // FILENAME
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    if (a1 == 1) ch1 ++;
    if (a2 == 1) ch1 ++;
    if (a3 == 1) ch1 ++;
    if (b1 == 1) ch1 ++;
    if (b2 == 1) ch1 ++;
    if (b3 == 1) ch1 ++;
    if (a1 == 2) ch2 ++;
    if (a2 == 2) ch2 ++;
    if (a3 == 2) ch2 ++;
    if (b1 == 2) ch2 ++;
    if (b2 == 2) ch2 ++;
    if (b3 == 2) ch2 ++;
    if (a1 == 3) ch3 ++;
    if (a2 == 3) ch3 ++;
    if (a3 == 3) ch3 ++;
    if (b1 == 3) ch3 ++;
    if (b2 == 3) ch3 ++;
    if (b3 == 3) ch3 ++;
    if (a1 == 4) ch4 ++;
    if (a2 == 4) ch4 ++;
    if (a3 == 4) ch4 ++;
    if (b1 == 4) ch4 ++;
    if (b2 == 4) ch4 ++;
    if (b3 == 4) ch4 ++;
    vc.PUBG(ch1);
    vc.PUBG(ch2);
    vc.PUBG(ch3);
    vc.PUBG(ch4);
    for (int i = 0 ; i < 4 ; ++ i) {
        if (vc[i] == 1) {
            h1 ++;
        }
        else if (vc[i] == 2) {
            h2 ++;
        }
    }
    if (h1 == 2 && h2 == 2) cout << "YES";
    else cout << "NO";
    ///time;
    return 0;
}
