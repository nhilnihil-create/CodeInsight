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

int a[N][2];
int v[N];

bool fnl(int p, int q) {
    return a[p][1] < a[q][1];
}

bool fnr(int p, int q) {
    return a[p][0] > a[q][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = gi();
    memset(v, 0, sizeof(v));
    list<int> l, r;
    for (int i = 0; i < n; i++) {
        a[i][0] = gi();
        a[i][1] = gi();
        l.push_back(i);
        r.push_back(i);
    }

    l.sort(fnl);
    r.sort(fnr);

    ll res = 0;
    int c = 0;
    list<int>::iterator itl = l.begin(), itr = r.begin();
    for (int i = 0; i < n; i++) {
        while (v[*itl])
            itl++;
        while (v[*itr])
            itr++;

        int d1 = c - a[*itl][1];
        int d2 = a[*itr][0] - c;

        if (d1 < 0 && d2 < 0) {
            v[*itl] = 1;
        } else if (d1 > d2) {
            v[*itl] = 1;
            res += d1;
            c = a[*itl][1];
        } else {
            v[*itr] = 1;
            res += d2;
            c = a[*itr][0];
        }
    }

    res += (c < 0 ? -c : c);

    itl = l.begin();
    itr = r.begin();
    if (a[*itl][1] <= 0 && a[*itr][0] >= 0) {
        memset(v, 0, sizeof(v));
        ll res2 = 0;
        if (-a[*itl][1] < a[*itr][0]) {
            c = a[*itl][1];
            res2 = -c;
            v[*itl] = 1;
        } else {
            c = a[*itr][0];
            res2 = c;
            v[*itr] = 1;
        }

        for (int i = 1; i < n; i++) {
            while (v[*itl])
                itl++;
            while (v[*itr])
                itr++;

            int d1 = c - a[*itl][1];
            int d2 = a[*itr][0] - c;

            if (d1 < 0 && d2 < 0) {
                v[*itl] = 1;
            } else if (d1 > d2) {
                v[*itl] = 1;
                res2 += d1;
                c = a[*itl][1];
            } else {
                v[*itr] = 1;
                res2 += d2;
                c = a[*itr][0];
            }
        }

        res2 += (c < 0 ? -c : c);

        res = MAX(res, res2);
    }

    cout << res << endl;

    return 0;
}
