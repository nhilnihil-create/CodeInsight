#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

template<typename T>
class BIT {
    public:
    int n;
    vector<T> bit; // i: [1,n]
    BIT(int size) {
        n = size + 1;
        bit = vector<T>(n+1,0);
    }

    void add(int i, T x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

    T sum(int i) {
        T ret = 0;
        while (i > 0) {
            ret += bit[i];
            i -= i & -i;
        }
        return ret;
    }

    T range(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

ll n;
vector<int> a;

bool check(int x) {
    vector<int> b(n);
    rep(i,n){
        b[i] = (a[i] >= x ? +1 : -1);
    }
    vector<ll> s(n+1);
    rep(i,n){
        s[i+1] = s[i] + b[i];
    }
    vector<pair<ll, int>> vp(n+1);
    rep(i,n+1) {
        vp[i] = {s[i],i};
    }
    sort(all(vp));

    // 小さい順に1..n+1の連番を振る
    vector<ll> c(n+1);
    rep(i,n+1){
        c[vp[i].second] = i+1;
    }

    // i < j, c[i] <= c[j] の個数を数える
    ll result = 0;
    BIT<int> bit(n+1);
    rep(i,n+1){
        result += bit.sum(c[i]);
        bit.add(c[i], 1);
    }

    return (n*(n+1)/2 + 1)/2 <= result;
}

int main(void) {
    cin >> n;
    a.resize(n);
    vector<int> meds(n);

    rep(i,n){
        cin >> a[i];
        meds[i] = a[i];
    }
    sort(all(meds));
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l+r)/2;
        if (check(meds[mid])) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << meds[l] << endl;
    return 0;
}
