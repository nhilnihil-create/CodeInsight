#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vl a(n);
    rep(i,0,n) {
        cin >> a[i];
    }
    if(a[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    rep(i,0,n-1) {
        if(a[i+1] - a[i] > 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ret = 0;
    rep(i,1,n) {
        if(a[i-1] + 1 == a[i]) 
            ret++;
        else 
            ret += a[i];
    }
    cout << ret << endl;
    return 0;
}
