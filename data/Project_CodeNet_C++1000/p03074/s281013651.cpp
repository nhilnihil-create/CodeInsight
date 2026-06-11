#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char prev = '1';
    vector<int> a;
    int ctr = 0;
    rep (i, s.size()) {
        switch (s[i]) {
            case '0':
                if (prev == '1') {
                    a.push_back(ctr);
                    ctr = 0;
                }
                prev = '0';
                ctr++;
                break;
            case '1':
                if (prev == '0') {
                    a.push_back(ctr);
                    ctr = 0;
                }
                ctr++;
                prev = '1';
                break;
        }
    }
    a.push_back(ctr);
    if (s[s.size() - 1] == '0') {
        a.push_back(0);
    }
    vector<int> b(a.size()+1);
    b[0] = 0;
    rep (i, a.size()) {
        b[i+1] = b[i] + a[i];
    }
    if (k * 2 + 1 >= b.size()) {
        cout << n << endl;
        exit(0);
    }
    int ans = 0;
    rep (i, 2 * k + 1, b.size()) {
        int p = b[i] - b[i - (2 * k + 1)];
        chmax(ans, p);
        i++;
    }
    cout << ans << endl;
}