//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 305
#define oo 1000000007
#define MOD 1000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

string s;
int n, k, dp[maxN][maxN][maxN];

int Solve(int i, int j, int k) {
    if (k < 0) return -oo;
    if (i > j) return 0;
    if (i == j) return 1;
    if (dp[i][j][k] != -1) return dp[i][j][k];

    int res;
    if (s[i] == s[j]) res = Solve(i+1, j-1, k)+2;
    else res = max(Solve(i+1, j-1, k-1)+2, Solve(i+1, j, k), Solve(i, j-1, k));

    return dp[i][j][k] = res;
}

int main () {
    cin >> s;
    n = s.length();
    scanf("%d", &k);

    fto(i, 0, n-1) fto(j, 0, n-1) fto(k, 0, n) dp[i][j][k] = -1;

    cout << Solve(0, n-1, k);

    return 0;
}

