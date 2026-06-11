/// Containers Start
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
/// C Header Files
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <math.h>
#include <stdio.h>
/// Containers End

using namespace std;

/// Math Start
#define PI acos(-1.0)
#define Pi 3.141592653589793
#define EPS (1e-7)
#define INF (0x3f3f3f3f)
/// Math End

/// Extra Start
#define nn '\n'
#define pb push_back
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
#define sz(a) int((a).size())
#define space " "
#define All(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
/// Extra End

#define rep(i, n) for (int i = 0; i < n; i++)
#define Cini(a)                                                                \
    int a;                                                                     \
    cin >> a;
#define Cinii(a, b)                                                            \
    int a, b;                                                                  \
    cin >> a >> b;
#define Ciniii(a, b, c)                                                        \
    int a, b, c;                                                               \
    cin >> a >> b >> c;
#define Cins(s)                                                                \
    string s;                                                                  \
    cin >> s;
#define Cinss(s1, s2)                                                          \
    string s1, s2;                                                             \
    cin >> s1 >> s2;
#define Cinc(c)                                                                \
    char c;                                                                    \
    cin >> c;
/// Functions End


/// Debug Start
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl;
#define deb3(x, y, z)                                                          \
    cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": "   \
         << z << endl;
/// Debug End

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

/**>>>>>>>>>>>>>>>>>>> END <<<<<<<<<<<<<<<<<<**/

/// template

#define int long long

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

ll lcd(ll a,ll b){
    return a/gcd(a,b)*b;
}

signed main(void) {
    cin.sync_with_stdio(false);
    cin.tie(0);
    Cinii(N,M);
    Cins(S); Cins(T);
    int L = lcd(N,M);
    unordered_map<int,char> m;
    // L[i * L/N + 1] = S[i]
    rep(i,N)m[i*(L/N)+1] = S[i];
    rep(i,M)
        if(m.count(i*(L/M)+1)==0)continue;
        else if(m[i*(L/M)+1]!=T[i]){
            cout << -1 << nn;
            return 0;
        }
    cout << L << nn;
    return 0;
}