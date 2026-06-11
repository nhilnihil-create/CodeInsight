//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1e5 + 5;
const int M = 1e5 + 5;
const ll OO = 1e18;
const int mod = 1e9 + 7;

int n,a[N],ans=1,tree[1<<20];

void build(int idx = 0, int st = 0, int en = n-1) {

    if(st==en) return tree[idx] = a[st], void();

    int mid = st + (en-st)/2, lf = 2*idx + 1, rt = lf + 1;
    build(lf,st,mid);
    build(rt,mid+1,en);
    tree[idx] = __gcd(tree[lf],tree[rt]);

}

int query(int a = 0, int b = n-1, int idx = 0, int st = 0, int en = n-1) {

    if(a>b) return 0;
    if(a>en || st>b) return 0;
    if(a<=st && en<=b) return tree[idx];
    int mid = st + (en-st)/2, lf = 2*idx + 1, rt = lf + 1;
    return __gcd(query(a,b,lf,st,mid),query(a,b,rt,mid+1,en));

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    build();

    for (int i = 0; i < n; ++i) {
        ans = max(ans, __gcd(query(0,i-1),query(i+1,n-1)));
    }

    cout << ans << '\n';

    return 0;
}