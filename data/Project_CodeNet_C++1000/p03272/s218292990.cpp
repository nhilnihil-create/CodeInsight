#include "bits/stdc++.h"
#define ll long long
#define PI 3.1415926535897932384626433832795l
#define MAX_NUM 1000000000
#define line printf("-----------------\n");
using namespace std;
int SET(int N, int pos) { return N = N | (1 << pos); }
int RESET(int N, int pos) { return N = N & ~(1 << pos); }
bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
template <typename T>
inline T __lcm(T a, T b)
{
    return (a * b) / __gcd(a, b);
}
struct node
{
    ll x, y, i;
};
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};


void solve()
{
    ll n,k;
    cin>>n>>k;
    cout<<n-k+1<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("inputf.txt", "r", stdin);
    //freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    solve();
    return 0;
}