#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>
#define PI acos(-1)
#define fs first
#define sc second
#define debug freopen("1.in","r",stdin),freopen("1.out","w",stdout);
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll maxn = 1e4 + 10;
const ll mod = 998244353;

string s[maxn];
int n, l, ans = 0, cnt[5];

int main(){
    ios;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        l = s[i].size();
        for (int j = 1; j < l; j++)
            if (s[i][j - 1] == 'A' && s[i][j] == 'B')
                ans++;
        if (s[i][0] == 'B')
            cnt[1]++;
        if (s[i][l - 1] == 'A')
            cnt[2]++;
        if (s[i][0] == 'B' && s[i][l - 1] == 'A')
            cnt[0]++;
    }
    int tmp = min (cnt[1], cnt[2]);
    ans += tmp;
    if(cnt[0] != 0 && cnt[0] == cnt[1] && cnt[0] == cnt[2])
        ans --;
    cout << ans;

    return 0;
}