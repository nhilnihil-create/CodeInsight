#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    string s;
    cin >> s;

    vector<string> t;
    t.push_back("KIHBR");
    t.push_back("KIHBRA");
    t.push_back("KIHBAR");
    t.push_back("KIHBARA");
    t.push_back("KIHABR");
    t.push_back("KIHABRA");
    t.push_back("KIHABAR");
    t.push_back("KIHABARA");
    t.push_back("AKIHBR");
    t.push_back("AKIHBRA");
    t.push_back("AKIHBAR");
    t.push_back("AKIHBARA");
    t.push_back("AKIHABR");
    t.push_back("AKIHABRA");
    t.push_back("AKIHABAR");
    t.push_back("AKIHABARA");

    bool flag = 0;
    rep(i, 16) if (t[i] == s) flag = 1;

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}