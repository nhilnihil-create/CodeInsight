#include <bits/stdc++.h>
#define lol long long
#define mp(x,y) make_pair(x,y)
using namespace std;

//const lol mod=1e9+7;

/*  author: H3XoRuSH  */

int main() {
    ios_base::sync_with_stdio(false);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n,h,w;
    cin >> n >> h >> w;
    lol ans=(n-h+1)*(n-w+1);
    cout << ans;
    return 0;
}
