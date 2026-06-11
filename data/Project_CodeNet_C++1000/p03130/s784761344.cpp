#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define ALL(c) (c).begin(), (c).end()
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int ary[4];
    rep(i,4) ary[i] = 0;
    rep(i,3)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        ary[a]++;
        ary[b]++;
    }
    int odd = 0;
    rep(i,4)
    {
        if (ary[i]%2==1) odd++;
    }
    if (odd == 0 || odd == 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    
    
}


