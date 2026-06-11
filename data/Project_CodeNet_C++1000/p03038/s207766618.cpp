#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod=1000000007;
//head

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    priority_queue<ll, vector<ll>, greater<ll>> q;

    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        q.push(a);
    }

    vector<pll> queries(m);
    for(int i = 0; i < m; i++) {
        ll b, c;
        cin >> b >> c;
        queries[i] = mp(c,b);
    }
    sort(all(queries));
    reverse(all(queries));

    for(int i = 0; i < m; i++) {
        pll p = queries[i];
        bool ok = false;
        ll b = p.second;
        while(b > 0 && p.first > q.top()) {
            q.pop();
            q.push(p.first);
            b--;
            ok = true;
        }
        if(!ok) break;
    }
    ll sum = 0;
    while(!q.empty()) {
        sum += q.top();
        q.pop();
    }
    cout << sum << endl;
    return 0;
}

