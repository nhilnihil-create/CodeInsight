#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int h, w, n;
int x, y;
char s[maxn], t[maxn];

bool solve1() {
    int L = 1, R = h;
    for (int i=n; i>=1; --i) {
        if(t[i] == 'U') R = min(h, R+1); else if(t[i] == 'D') L = max(1, L-1);
        if(s[i] == 'U') ++L; else if(s[i] == 'D') --R;
        if(L>R) return 1;
    } return x<L || x>R;
}

bool solve2() {
    int L = 1, R = w;
    for (int i=n; i>=1; --i) {
        if(t[i] == 'L') R = min(w, R+1); else if(t[i] == 'R') L = max(1, L-1);
        if(s[i] == 'L') ++L; else if(s[i] == 'R') --R;
        if(L>R) return 1;
    } return y<L || y>R;
}

int main() {
    scanf("%d%d%d", &h, &w, &n);
    scanf("%d%d", &x, &y);
    scanf("%s%s", s+1, t+1);
    puts((solve1()||solve2())? "NO": "YES");
    return 0;
}
