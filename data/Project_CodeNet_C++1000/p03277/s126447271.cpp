#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task ""

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;

struct BIT
{
    int cnt[maxn];
    void init(void)
    {
        fill(begin(cnt), end(cnt), 0);
    }
    void update(int i, int v)
    {
        for(; i<=maxn-5; i+=i&-i){
            cnt[i] += v;
        }
    }
    int sum(int i)
    {
        int res = 0;
        for (; i; i-=i&-i){
            res += cnt[i];
        }
        return res;
    }
}ft;

int N, a[maxn];

bool check(int x)
{
    vector<int> sum(N + 5);
    for (int i=1; i<=N; ++i){
        if (a[i] <= x) sum[i] = sum[i-1] + 1;
        else sum[i] = sum[i-1] - 1;
    }
    ft.init();
    ft.update(N + 1, 1);
    ll res = 0;
    for (int i=1; i<=N; ++i){
        res += ft.sum(sum[i] + N);
        ft.update(sum[i] + N + 1, 1);
    }
    ll val = ( 1ll * N * ( N + 1)) / 2;
    val /= 2;
    return res >= val + 1;
}

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> N;
    for (int i=1; i<=N; ++i){
        cin >> a[i];
    }
    int l=1, r=1e9, mid;
    while (l <= r){
        mid = (l + r) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << '\n';
    return 0;
    for (int i=1; i<=30; ++i)
        cerr << i << ' ' << check(i) << '\n';
}
