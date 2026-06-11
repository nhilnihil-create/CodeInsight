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

int l[200000];
int n;

int poss(int m) {
    vector<pair<int, int> > v;
    v.push_back({0, l[0]});
    for (int i = 1; i < n; i++) {
        if (l[i] > l[i-1]) {
            v.push_back({0, l[i] - l[i-1]});
        } else {
            int s = l[i-1];
            int c = 0;
            while (s > l[i]) {
                pair<int, int> p = v.back(); v.pop_back();
                c = p.first;
                s -= p.second;
            }
            if (s < l[i])
                v.push_back({c, l[i] - s});
            s = 0;
            while (v.size() && v.back().first == m-1) {
                s += v.back().second; v.pop_back();
            }
            if (v.empty())
                return 0;
            pair<int, int> p = v.back(); v.pop_back();
            if (p.second > 1)
                v.push_back({p.first, p.second - 1});
            v.push_back({p.first + 1, 1});
            if (s)
                v.push_back({0, s});
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n = gi();
    for (int i = 0; i < n; i++)
        l[i] = gi();

    int L = 1, R = n;
    while (L < R) {
        int M = (L+R)/2;
        if (poss(M))
            R = M;
        else
            L = M+1;
    }

    printf("%d\n", L);

    return 0;
}
