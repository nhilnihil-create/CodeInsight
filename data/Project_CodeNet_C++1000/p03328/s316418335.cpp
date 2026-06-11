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

void solve()
{
    int a, b;
    vector<int> v;
    cin >> a >> b;
    for(int i = 1; i <= 999; i++)
    {
        int x = i*i+i;
        x/=2;
        v.push_back(x);
    }
    for(int i = 0; i < v.size()-1; i++)
    {
        if(v[i]<a) continue;
        if(v[i+1]<b)continue;
        if(v[i]-a!=v[i+1]-b) continue;
        cout << v[i]-a << "\n";
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t;
    while(t--) solve();
}
