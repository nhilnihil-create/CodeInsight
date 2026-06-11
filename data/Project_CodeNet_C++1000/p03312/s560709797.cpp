#include <bits/stdc++.h>

#define sc second
#define fr first
#define mk make_pair
#define pb push_back
#define int long long

using namespace std;

const int N = (1e6 + 5);
const int inf = (1e18 + 7);

int n;
int a[N];
int ans = inf;
int sl,sr,now;

vector <pair<int,int> > v;

main () {
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    now = 1;

    for (int i = 1; i <= n; i ++) {
        sr += a[i];
        while (now <= i && abs(sl - sr) >= abs(sl + a[now] - (sr - a[now])))
            sl += a[now],sr -= a[now],now ++;
        v.pb(mk(min(sl,sr),max(sl,sr)));
    }
    sl = sr = 0;
    now = n;
    for (int i = n; i >= 2; i --) {
        sr += a[i];
        while (now >= i && abs(sl - sr) >= abs(sl + a[now] - (sr - a[now])))
            sl += a[now],sr -= a[now],now --;
        ans = min(ans,max(sl,max(sr,v[i - 2].sc)) - min(sl,min(sr,v[i - 2].fr)));
    }
    cout << ans << endl;
}
