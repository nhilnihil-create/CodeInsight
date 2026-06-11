#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << ":" << #x << " = " << (x) << endl;
#else
#define dbg
#endif

#pragma endregion Macros

int main()
{
    int N;
    cin >>N ;
    vector<int> b(N+1);
    rep(i, N) cin >> b[i + 1];

    stack<int> ans;

    bool noans;
    for (int i = N; i >= 1; i--) {
        noans = true;
        for (int j = b.size() - 1; j >= 1; j--) {
            if(j==b[j]) {
                ans.push(j);
                noans = false;
                b.erase(b.begin()+j);
                break;
            }
        }

        if (noans) break;
    }


    if(noans) {
        cout << -1 << endl;
        return 0;
    }
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }

}
