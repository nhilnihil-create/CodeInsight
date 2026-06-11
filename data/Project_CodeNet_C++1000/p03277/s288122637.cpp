#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) (a).begin(),(a).end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define ub(s,x) upper_bound(all(s),x)-s.begin()
#define uniq(a) a.erase(unique(all(a)),a.end())
#define debug(x) cout<<#x<<": "<<x<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
typedef long long ll;
const int INF = 1e9;


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
    vector<ll> c(n+1);
    rep(i,n+1){
        c[vp[i].second] = i;
    }

    ll result = 0;
    BIT<int> bit(n+1);
    rep(i,n+1){
        result += bit.sum(c[i]+1);
        bit.add(c[i]+1, 1);
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
        // debug(mid);
        if (check(meds[mid])) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << meds[l] << endl;
    return 0;
}

/*
int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
    }

    vector<ll> med;
    // [l,r)
    rep(r,n+1)rep(l,r){
        printf("[l,r) = [%d,%d)\n", l,r);
        vector<ll> v;
        for(int i = l; i < r; i++){
            cout<<a[i]<<" ";
            v.push_back(a[i]);
        }
        cout<<endl;

        sort(all(v));
        med.push_back(v[v.size()/2]);
        cout<<"med: "<<med.back()<<endl;
        cout<<"---------------"<<endl;
    }
    sort(all(med));

    cout<<med[med.size()/2]<<endl;
        for(ll x : med){
            cout<<x<<" ";
        }
        cout<<endl;
    return 0;
}
*/