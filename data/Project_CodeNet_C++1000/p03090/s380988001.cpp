#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
vector< pair<int, int> > v;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (n % 2 == 0) {
                if (i + j != n + 1) v.push_back(make_pair(i, j));
            } else {
                if (i + j != n && !(i == n && j == n)) v.push_back(make_pair(i, j));
            }
        }
    }

    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++) {
        printf("%d %d\n", v[i].X, v[i].Y);
    }
    return 0;
}
