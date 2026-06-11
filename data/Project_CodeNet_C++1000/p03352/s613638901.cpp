#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(a) a.begin(), a.end()

const int maxn = 200010;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LINF = 1e18;
ll n, m, a[maxn];
map<int, int> M, N;
set<int> S;
string s;

int exp(int a, int b)
{
    if(b==0)return 1;
    if(b==1) return a;
    int x = exp(a, b/2);
    x*=x;
    if(b%2)return x*a;
    return x;
}
void solve()
{
    cin >> n;
    vector<int> v;
    for(int i = 1; i < 1000; i++)
        for(int j = 2; j < 10; j++)
            v.pb(exp(i, j));
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i]>n)
        {
            cout << v[i-1];
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t;
    while(t--) solve();
}
