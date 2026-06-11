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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = gi();
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(gi());
    ll l = 2, r = 2;
    for (int i = 0; i < n; i++) {
        ll x = s.top(); s.pop();
        ll mn = (l/x)*x; if (mn < l) mn += x;
        ll mx = (r/x)*x;
        l = mn; r = mx+x-1;
        if (l > r) {
            printf("-1\n");
            return 0;
        }
    }

    cout << l << " " << r << endl;

    return 0;
}
