#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    int x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
    long long a = rng();
    return a;
}

int n, v[200002];
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    int st = 1;
    int dr = n-1;
    int ans = 1;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(v[mid] <= v[n] / 2)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    if(ans == n-1)
    {
        cout << v[n] << " " << v[n-1] << '\n';
        return 0;
    }
    int pa = v[ans];
    int pb = v[ans+1];
    int midpoint = v[n] / 2;
    cout << v[n] << " ";
    if(v[n] % 2 == 1)
    {
        if(min(abs(midpoint + 1 - pa), abs(midpoint - pa)) < min(abs(midpoint + 1 - pb), abs(midpoint - pb)))
            cout << pa << " ";
        else
            cout << pb << " ";
    }
    else
    {
        if(abs(midpoint - pa) < abs(midpoint - pb))
            cout << pa << " ";
        else
            cout << pb << " ";
    }
    return 0;
}
