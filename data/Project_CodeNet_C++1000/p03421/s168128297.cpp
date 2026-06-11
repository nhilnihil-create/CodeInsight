#include<bits/stdc++.h>
using namespace std;
int n, a, b, s[300010];
void swa(int l, int r)
{
    while (l < r){
        swap(s[l], s[r]);
        ++l, --r;
    }
}
bool solve()
{
    int ta = n, tb = 1, ma = -1, r = n;
    if (tb < b){
        if (r - (b - tb) < 1) return false;
        swa(r - (b - tb), r);
        r -= (b - tb + 1);
        ta -= (b - tb);
        ma = (b - tb + 1);
        tb = b;
    }
    if (ta < a) return false;
    while (ta > a){
        if (ta - a + 1 > ma){
            if (r - ma + 1 < 1) return false;
            swa(r - ma + 1, r);
            r -= ma;
            ta -= (ma - 1);
        }else{
            if (r - (ta - a) < 1) return false;
            swa(r - (ta - a), r);
            r -= (ta - a + 1);
            ta -= ma;
        }
    }
    return true;
}
int main()
{
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; ++i) s[i] = i;
    if (a + b > n + 1) puts("-1");
    else{
        if (solve()){
            for (int i = 1; i <= n; ++i) printf(i == n ? "%d\n" : "%d ", s[i]);
        }else puts("-1");
    }
    return 0;
}