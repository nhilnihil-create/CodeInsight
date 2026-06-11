#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll BASE = 200000LL;

int n;
ll threshold;
vector<ll> a;

class BIT{
    public:
    int n;
    vector<ll> bit;

    BIT(int n): n(n){
        bit.resize(n);
        fill(all(bit), 0LL);
    }

    void add(int idx, ll x){
        for(int i=idx;i<=n;i+=i&-i) bit[i] += x;
    }

    ll sum(int end){
        ll ret = 0LL;
        for(int i=end;i>=1;i-=i&-i) ret += bit[i];
        return ret;
    }
};

bool judge(ll median){
    vector<ll> b(n+1);
    b[0] = BASE;
    reppp(i, 1, n+1){
        b[i] = b[i-1] + (a[i-1]>=median ? 1LL : -1LL);
    }

    ll cnt = 0LL;
    BIT bit = BIT(BASE+n);
    bit.add(b[0], 1LL);
    reppp(i, 1, n+1){
        cnt += bit.sum(b[i]);
        bit.add(b[i], 1LL);
    }
    return cnt >= threshold;
}

int main(){
    cin >> n;
    a.resize(n);
    rep(n) cin >> a[i];

    threshold = ll(n) * ll(n+1) / 2LL;
    threshold = (threshold+1LL) / 2LL;

    vector<ll> aa(a);
    sort(all(aa));
    int ok = 0; // 中央値はok以上
    int ng = n; // 中央値はng未満
    while(ng-ok > 1){
        int mid = (ng+ok)/2;
        
        if(judge(aa[mid])){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << aa[ok] << endl;
}