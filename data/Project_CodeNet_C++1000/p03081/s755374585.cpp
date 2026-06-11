#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;

int n, q;
string s;
char t[200010], d[200010];

int check(int cur){
    if(s[cur] == '#') return cur;
    rep(i, q)if(s[cur] == t[i]){
        if(d[i] == 'L') --cur;
        else ++cur;
        if(s[cur] == '#') return cur;
    }
    return cur;
}

int main(){
    scanf("%d%d", &n, &q);
    cin >> s;
    s = "#" + s + "#";
    rep(i, q) scanf(" %c %c", &t[i], &d[i]);
    if(check(0) == n+1 || check(n-1) == 0){
        printf("0\n");
        return 0;
    }
    int high = n+1;
    int low = 0;
    while(high - low > 1){
        int mid = (high + low) / 2;
        if(check(mid) == 0) low = mid;
        else high = mid;
    }
    int l = high;
    high = n+1;
    low = 0;
    while(high - low > 1){
        int mid = (high + low) / 2;
        if(check(mid) == n+1) high = mid;
        else low = mid;
    }
    int r = high;
    printf("%d\n", r - l);
}