#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int counter[200005];
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n)
    {
        cin >> a[i];
        counter[a[i]]++;
    }
    vector<int> temp;
    int kind = 0;
    for (auto s : counter)
    {
        if(s!=0)
        {
            temp.push_back(s);
            kind++;
        }
    }
    sort(temp.begin(),temp.end());
    ll ans = 0;
    rep(i, kind-k)
    {
        ans += (ll)temp[i];
    }
    cout << ans << endl;
    
}