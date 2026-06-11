#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}

int const MAX_T = 100010;
vector<int> add[MAX_T+10];
vector<int> del[MAX_T+10];

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> s(n),t(n),c(n);
    rep(i,n) {
        cin >> s[i] >> t[i] >> c[i];
        add[s[i]].push_back(c[i]);
        del[t[i]].push_back(c[i]);
    }

    int res = 0;
    set<int> st;
    rep(j,MAX_T) {
        vector<int> dame;
        for(int x : add[j]) {
            if(st.find(x) != st.end()) dame.push_back(x);
            st.insert(x);
        }
        chmax(res,(int)size(st));
        for(int x : del[j]) {
            bool ok = true;
            for(int y : dame) {
                if(x == y) ok = false;
            }
            if(ok) st.erase(x);
        }
    }
    cout << res << endl;
    return 0;
}