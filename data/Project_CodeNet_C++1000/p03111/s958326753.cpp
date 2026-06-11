#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb                push_back
#define mp                make_pair
#define ll                long long
#define ld                long double
#define pii               pair <ll, ll>
#define piii              pair <ll, pii>
#define F                 first
#define S                 second

#define newline           printf("\n")
#define minusone          printf("-1\n")
#define zeroo             printf("0\n")
#define scl1(a)           scanf("%lld", &a)
#define scl2(a, b)        scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)     scanf("%lld %lld %lld", &a, &b, &c)
#define prl1(a)           printf("%lld\n", a)
#define prl2(a, b)        printf("%lld %lld\n", a, b)
#define ssl1(s)           scanf(" %[^\n]", s)
#define scd1(a)           scanf("%lf", &a)
#define scd2(a, b)        scanf("%lf %lf", &a, &b)
#define prd(a)            printf("%lf\n", a)
#define prld(a)           printf("%Lf\n", a)
#define prcase(cs)        printf("Case %lld: ", cs)
#define cin1(a)           cin >> a
#define cin2(a, b)        cin >> a >> b
#define cin3(a, b, c)     cin >> a >> b >> c
#define cin4(a, b, c, d)  cin >> a >> b >> c >> d
#define cot1(a)           cout << a << "\n"
#define cot2(a, b)        cout << a << " " << b << "\n"
#define cot3(a, b, c)     cout << a << " " << b << " " << c << "\n"
#define cot4(a, b, c, d)  cout << a << " " << b << " " << c << " " << d << "\n"
#define cotline           cout << "\n"
#define cotminus          cout << "-1\n"
#define cot0              cout << "0\n"
#define cotyes            cout << "YES\n"
#define cotno             cout << "NO\n"
#define cotcase(cs)       cout << "Case " << cs << ": "

#define reversed(s)       reverse(s.begin(), s.end())
#define asort(s)          sort(s.begin(), s.end())
#define dsort(s)          sort(s.rbegin(), s.rend())
#define all(s)            s.begin(), s.end()
#define uniq(s)           s.resize(distance(s.begin(),unique(s.begin(), s.end())))
#define found(s, x)       (s.find(x) != s.end())

#define for0(i, n)        for (i = 0; i < n; i++)
#define for1(i, n)        for (i = 1; i <= n; i++)
#define fora(i, a, b)     for (i = a; i <= b; i++)
#define forb(i, b, a)     for (i = b; i >= a; i--)
#define fori(it, s)       for(auto it = s.begin(); it != s.end(); it++)

#define FR                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(a, x)          memset(a, x, sizeof a)
#define bitcount(n)       __builtin_popcountll(n)

//#define pi              3.1415926536
#define pi                acos(-1)

const ll INF = LLONG_MAX;
const ll SZ = 4e5+5;
const ll mod = 1e9+7;


bool check(ll x, ll pos) {
    return (x & (1LL << pos));
}

ll set1(ll x, ll pos) {
    return (x | (1LL << pos));
}

ll n, ans = INF;
ll n1, n2, n3;
ll a[12];
ll dp[300][300][300];

void solve(ll msk1, ll msk2, ll msk3) {
    if(bitcount(msk1) == n-1 || bitcount(msk2) == n-1 || bitcount(msk3) == n-1) return;
    if(bitcount(msk1)+bitcount(msk2) == n || bitcount(msk2)+bitcount(msk3) == n || bitcount(msk1)+bitcount(msk3) == n) return;
    if(dp[msk1][msk2][msk3] != -1) return;

    ll i;
    ll t1(0), t2(0), t3(0), res(0);
    ll c1 = bitcount(msk1) - 1;
    ll c2 = bitcount(msk2) - 1;
    ll c3 = bitcount(msk3) - 1;

    for0(i, n) {
        if(check(msk1, i)) t1 += a[i];
        else if(check(msk2, i)) t2 += a[i];
        else if(check(msk3, i)) t3 += a[i];
    }

    res = abs(n1 - t1) + (10 * c1);
    res += abs(n2 - t2) + (10 * c2);
    res += abs(n3 - t3) + (10 * c3);

    dp[msk1][msk2][msk3] = res;
    ans = min(ans, res);

    for0(i, n) {
        if(check(msk1, i) || check(msk2, i) || check(msk3, i)) continue;
        solve(set1(msk1, i), msk2, msk3);
    }

    for0(i, n) {
        if(check(msk1, i) || check(msk2, i) || check(msk3, i)) continue;
        solve(msk1, set1(msk2, i), msk3);
    }

    for0(i, n) {
        if(check(msk1, i) || check(msk2, i) || check(msk3, i)) continue;
        solve(msk1, msk2, set1(msk3, i));
    }
}

int main() {
    ll cs = 0, tc = 1, x, y, z, i, j, k, g, p, q, sum = 0, c = 0, t = 0;
//    ll a, b, d;
    string s, s1, s2;

    cin4(n, n1, n2, n3);
    for0(i, n) cin1(a[i]);

    ms(dp, -1);

    for0(i, n) {
        for0(j, n) {
            for0(k, n) {
                if(i == j || j == k || i == k) continue;
                solve(set1(0LL, i), set1(0LL, j), set1(0LL, k));
            }
        }
    }

    cot1(ans);

    return 0;
}

