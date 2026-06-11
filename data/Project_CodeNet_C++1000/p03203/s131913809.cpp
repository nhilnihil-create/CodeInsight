#include <bits/stdc++.h>

using namespace std;

int h, w, n;
set<int> S[200010];

int main(){
    scanf("%d %d %d", &h, &w, &n);
    for(int i = 1, x, y; i <= n; i++){
        scanf("%d %d", &x, &y);
        S[y].insert(x);
    }

    int x = 1, y = 1, ans = h;
    while(true){
        auto it = S[y].lower_bound(x);
        if(it != S[y].end()) ans = min(ans, *it - 1);

        if(x == h || S[y].find(x + 1) != S[y].end()) break;
        x++;
        if(!(y == w || S[y + 1].find(x) != S[y + 1].end())) y++;
    }
    printf("%d\n", ans);
    return 0;
}