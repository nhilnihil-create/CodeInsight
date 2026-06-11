#include <bits/stdc++.h>
using namespace std;
const int Maxb = 31;
int n;
map <int, int> M;
int res;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        M[a]++;
    }
    for (int i = Maxb - 1; i >= 0; i--)
        for (map <int, int>::iterator it = M.begin(); it != M.end() && 2 * it->first <= (1 << i); it++) {
            if (it->second == 0) continue;
            int nd = (1 << i) - it->first;
            if (nd == it->first) {
                int tk = it->second / 2;
                it->second -= 2 * tk;
                res+=tk;
            } else {
                map <int, int>::iterator it2 = M.find(nd);
                if (it2 != M.end()) {
                    int tk = min(it->second, it2->second);
                    it->second -= tk; it2->second -= tk;
                    res += tk;
                }
            }
        }
    printf("%d\n", res);
    return 0;
}