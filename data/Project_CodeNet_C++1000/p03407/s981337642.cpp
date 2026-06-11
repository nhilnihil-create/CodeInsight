#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using edge = struct {int to; ll cost;};

#define mod 1000000007
#define REP(i, n) for (int i = 0; i < n; i++)
#define INF (1 << 29)


//long C(long n, long r);
//long long gcd(long long a, long long b);
//long long lcm(long long a, long long b);

int h, w, d;
int a[301][301];
int q;
int l[100001], r[100001];
vector<pair<int, int>> cood(90001);
vector<int> cost(900001, 0);


void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(c <= a+b) {
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
}

int main()
{
    solve();
    return 0;
}