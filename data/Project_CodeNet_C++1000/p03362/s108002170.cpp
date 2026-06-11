#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
//#include <unordered_map>
#define Fbo friend bool operator < (node a, node b)
#define mem(a, b) memset(a, b, sizeof(a))
#define FOR(a, b, c) for (int a = b; a <= c; a++)
#define RFOR(a, b, c) for (int a = b; a >= c; a--)
#define off ios::sync_with_stdio(0)
#define sc(a) scanf("%d",&a)
#define pr(a) printf("%d\n",a);
#define SC(n,m) scanf("%d%d",&n,&m)
bool check1(int a) { return (a & (a - 1)) == 0 ? true : false; }

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;//1e10
const int mod = 1e9 + 7;
const int Maxn = 1e5 + 5;
const int M = Maxn * 20;
const double pi = acos(-1.0);
const double eps = 1e-8;

int a[Maxn], k = 1;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ll n;
    cin >> n;
    cout << 3;
    for (int i = 11;i <= 55555 ; i++) {
        if (is_prime(i)&&i%10==3) {
            cout << " " << i;
            k++;
        }
        if (k == n)break;
    }
}