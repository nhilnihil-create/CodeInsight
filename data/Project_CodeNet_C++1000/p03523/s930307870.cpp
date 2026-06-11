#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 100000000


using namespace std;

string t = "AKIHABARA";

string s;
int main()
{
    //COMinit();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int now = 0;
    for (int i = 0; i < s.size(); ++i) {
        while (now < t.size() && s[i] != t[now]) {
            if (t[now] == 'A')
                ++now;
            else {
                cout << "NO\n";
                return 0;
            }
        }
        if (now == t.size()) {
            cout << "NO\n";
            return 0;
        }
        ++now;
    }
    while (now < t.size()) {
        if (t[now] == 'A')
            ++now;
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return  0;
}