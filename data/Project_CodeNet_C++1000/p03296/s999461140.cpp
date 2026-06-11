#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long   ll;
typedef double      db;
typedef long double ldb;

typedef pair <int, int> pii;
typedef pair <ll,  ll>  pll;
typedef pair <ll,  db>  pdb;
typedef pair <ldb, ldb> pldb;

template <typename T>
void   Debug (T begin, T end);
int    si    ();
ll     sl    ();
string ss    (int); 
db     sf    ();
ldb    slf   ();
void   pi    (int, char = '\n');
void   pl    (ll, char = '\n');
void   pf    (db, char = '\n');
void   plf   (ldb, char = '\n');
void   ps    (string, char = '\n');

ll russian(ll, ll, ll);
ll fastpow(ll, ll, ll);
ll slowpow(ll, ll, ll);
ll _gcd(ll, ll);
ll _lcm(ll, ll);
ll extgcd(ll, ll, ll&, ll&);
ll _inv(ll, ll);

const int INF  = 1e9;
const ll  LINF = 1e18;

int main()
{
    int n = si(), res = 0;
    int last = 0;

    for (int i = 0; i < n; ++i)
    {
        int a = si();
        if (a == last)
            ++res,
            last = 0;
        else
            last = a;
    }
    pi(res);

    return 0;
}

template <typename T>
void Debug(T begin, T end)
{
    printf("\nDEBUG:\n");
    while (begin != end)
        printf("%d ", *begin),
        begin++;
    printf("\n\n");
}

template <typename T>
T scanf_t(string s)
{
    T a;
    scanf(s.c_str(), &a);
    return a;
}

template <typename T>
void printf_t(T a, string s, char end_l)
{
    s.push_back(end_l);
    printf(s.c_str(), a);
}

int si() { return scanf_t<int>("%d"); }
ll sl() { return scanf_t<ll>("%lld"); }
db sf() { return scanf_t<db>("%f"); }
ldb slf() { return scanf_t<ldb>("%Lf"); }

void pi(int a, char end_l) { printf_t<int>(a, "%d", end_l); }
void pl(ll a, char end_l) { printf_t<ll>(a, "%lld", end_l); }
void pf(db a, char end_l) { printf_t<db>(a, "%lf", end_l); }
void plf(ldb a, char end_l) { printf_t<ldb>(a, "%Lf", end_l); }

void ps(string a, char end_l)
{
    string s = "%s";
    s.push_back(end_l);
    printf(s.c_str(), a.c_str());
}

string ss(int NN)
{
    char T[NN];
    scanf("%s", T);
    return (string)T;
}

ll fastpow(ll a, ll k, ll m)
{
    ll r = 1LL;
    while (k)
    {
        if (k & 1LL)
            r = (r * a) % m;
        a = (a * a) % m;
        k >>= 1LL;
    }
    return r;
}

ll slowpow(ll a, ll k, ll m)
{
    ll r = 1LL;
    while (k)
    {
        if (k & 1LL)
            r = russian(r, a, m);
        a = russian(a, a, m);
        k >>= 1LL;
    }
    return r;
}

ll russian(ll a, ll k, ll m)
{
    ll r = 0LL;
    while (k)
    {
        if (k & 1LL)
            r = (r + a) % m;
        a = (a + a) % m;
        k >>= 1LL;
    }
    return r;
}

ll _gcd(ll a, ll b)
{
    while (b)
        swap(a %= b, b);
    return a;
}

ll _lcm(ll a, ll b)
{
    return a / _gcd(a, b) * b;
}

ll extgcd(ll a, ll b, ll& k, ll& l)
{
    if (b == 0)
    {
        k = 1; l = 0;
        return a;
    }    
    ll res = extgcd(b, a % b, l, k);
    l -= a / b * k;
    return res;
}

ll _inv(ll a, ll p)
{
    return fastpow(a, p - 2, p);
}