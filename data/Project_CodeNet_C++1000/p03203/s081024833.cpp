#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()

const double PI = acos(-1.0);
const int MAXN = 200005;

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

int h, w, n;
vector<int> pos[MAXN];

int main () {
    scanf("%d%d%d", &h, &w, &n);
    fto(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        pos[x].pb(y);
    }

    int maxY = 1;
    fto(x, 2, h) {
        bool blocked = false;
        for(int y: pos[x]) {
            if (y == maxY+1)
                blocked = true;
            else if (y <= maxY) {
                printf("%d", x-1);
                return 0;
            }
        }

        if (!blocked)
            ++maxY;
    }

    printf("%d", h);

    return 0;
}
