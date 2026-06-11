#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

#define N 100000

int l[N];
int r[N];
int v[N];

bool fnl(int p, int q) {
    return r[p] < r[q];
}

bool fnr(int p, int q) {
    return l[p] > l[q];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = gi();
    list<int> sl, sr;
    for (int i = 0; i < n; i++) {
        l[i] = gi();
        r[i] = gi();
        sl.push_back(i);
        sr.push_back(i);
    }

    sl.sort(fnl);
    sr.sort(fnr);

    ll res = 0;

    for (int t = 0; t < 2; t++) {
        list<int>::iterator itl = sl.begin(), itr = sr.begin();
        int c;
        ll resa;
        memset(v, 0, sizeof(v));
        if (t) {
            c = r[*itl];
            if (c > 0)
                continue;
            resa = -c;
            v[*itl] = 1;
        } else {
            c = l[*itr];
            if (c < 0)
                continue;
            resa = c;
            v[*itr] = 1;
        }
        for (int i = 1; i < n; i++) {
            while (v[*itl])
                itl++;
            while (v[*itr])
                itr++;

            int d1 = c - r[*itl];
            int d2 = l[*itr] - c;

            if (d1 < 0 && d2 < 0) {
                v[*itl] = 1;
            } else if (d1 > d2) {
                v[*itl] = 1;
                resa += d1;
                c = r[*itl];
            } else {
                v[*itr] = 1;
                resa += d2;
                c = l[*itr];
            }
        }
        resa += (c < 0 ? -c : c);

        res = MAX(res, resa);
    }

    cout << res << endl;

    return 0;
}
