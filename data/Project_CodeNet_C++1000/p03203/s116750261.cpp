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

int m[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X = gi();
    int Y = gi();
    int n = gi();

    for (int i = 0; i < X; i++)
        m[i] = Y;
    m[X] = 0;
    for (int i = 0; i < n; i++) {
        int x = gi()-1;
        int y = gi()-1;
        m[x] = MIN(m[x], y);
    }

    int y = 0;
    for (int i = 0; ; i++) {
        if (m[i+1] <= y) {
            printf("%d\n", i+1);
            break;
        }
        if (m[i+1] > y+1)
            y++;
    }

    return 0;
}
