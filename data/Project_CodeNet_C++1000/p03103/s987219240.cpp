#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 

vector<pi> drinks;
 
int32_t main()
{
    fast;
    int n, m, a, b, cost = 0, cans = 0, idx = 0; cin >> n >> m;
    For(i, 0, n) {
        cin >> a >> b;
        drinks.pb({a, b});
    }
    sort(drinks.begin(), drinks.end());
    For(i, 0, n) {
        if(cans >= m) break;
        cans += drinks[i].second;
        idx = i;
    }

    
    For(i, 0, idx) {
        cost += drinks[i].first * drinks[i].second;
        m -= drinks[i].second;
    }

    cost += drinks[idx].first * (m);

    cout << cost << "\n";
     
    return 0;
}