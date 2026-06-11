#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

bool test(const vector<int> &ans, vector<ll> po, int m) {
    vector<int> test((int)ans.size()+1);
    rep(i,ans.size()) {
        test[i+1] = test[i]^ans[i];
    }
    vector<int> idx(2*po[m],INF);
    rep(i,ans.size()) {
        if (idx[ans[i]]==INF) idx[ans[i]] = i;
        else {
            int ret = test[i+1]^test[idx[ans[i]]];
            cout << ret << '\n';
        }
    }
}

void experiment() {
    int n,k; cin>>n>>k;
    int ret = 0;
    rep(i,n) {
        if (i==k) continue;
        ret ^= i;
    }
    cout << ret << '\n';
}

int main(int argc, char const *argv[]) {
    ll m,k; cin>>m>>k;
    vector<ll> po(20);
    int t = 1;
    rep(i,20) {
        po[i] = t;
        t *= 2;
    }
    auto ex = [](){
        cout << -1 << '\n';
        exit(0);
    };
    if (k>=po[m]) ex();
    if (m==0 && k!=0) ex();
    if (m==1 && k!=0) ex();
    if (k==0) {
        rep(i,po[m]) {
            cout << i << ' ' << i;
            if (i+1!=po[m]) cout<<' ';
            else cout << '\n';
        }
        return 0;
    }
    vector<int> x,y;
    vector<int> ans;
    ans.reserve(2*po[m]);
    for (int i = 0; i < po[m]; ++i) {
        if (i == k) continue;
        x.push_back(i);
        y.push_back(i);
    }
    sort(y.begin(), y.end(), greater<>());
    for (auto &&e: x) ans.push_back(e);
    ans.push_back(k);
    for (auto &&e: y) ans.push_back(e);
    ans.push_back(k);
    
    print(ans);
    return 0;
}