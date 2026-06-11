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

const int MAXN = 200005;
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

int n, a[MAXN];

struct BigString {
    vector<pii> s;
    int len;
    int alpha;

    BigString(int alpha): alpha(alpha) {
        len = 0;
    }

    void insertBlock(int ch, int siz) {
        if (!s.empty() && ch == s.back().ff)
            s.back().ss += siz;
        else
            s.pb({ch, siz});
        len += siz;
    }

    void cut(int newLen) {
        while (len - s.back().ss >= newLen) {
            len -= s.back().ss;
            s.pop_back();
        }
        s.back().ss -= len - newLen;
        len = newLen;
        //printf("len: %d\n", len);
    }

    bool inc() {
        int removedLen = 0;
        while (!s.empty() && s.back().ff == alpha - 1) {
//            int x = s[i].ss;
//            insertBlock(0, x);
            removedLen += s.back().ss;
            s.pop_back();
        }
        if (s.empty())
            return false;

        if (s.back().ss == 1) {
            ++s.back().ff;
            if (sz(s) > 1 && s[sz(s) - 2].ff == s.back().ff) {
                s.pop_back();
                s.back().ss += 1;
            }
        } else {
            s.back().ss -= 1;
            s.push_back({s.back().ff + 1, 1});
        }
        if (removedLen > 0)
            s.push_back({0, removedLen});

        return true;
    }

    void print() {
        printf("alpha, len: %d %d\n", alpha, len);
        for(pii p: s)
            printf("%d %d\n", p.ff, p.ss);
    }
};

bool check(int alpha) {
//    debug(alpha);
    BigString str(alpha);

    fto(i, 0, n-1) {
        if (a[i] > str.len)
            str.insertBlock(0, a[i] - str.len);
        else {
            str.cut(a[i]);
            if (!str.inc())
                return false;
        }
//        str.print();
//        debug(i);
    }

    return true;
}

int main () {
    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    int lo = 1, hi = n, res = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            res = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }

    printf("%d", res);

    return 0;
}
