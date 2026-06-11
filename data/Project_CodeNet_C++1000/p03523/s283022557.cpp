#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* メモリ食い過ぎ注意 */
#define int ll
#define ALL(v) v.begin(), v.end()
#define _REP(i, n) for (int i = 0; i < n; i++)
#define REP(n) _REP(i, n)

/* define const */
const ll INF = (1ll << 60);
const ll MOD = (ll)1e9 + 7;
const ll MAX = 1e6;
/* end defineing */

signed main()
{
    string s;
    cin >> s;
    if (s.length() > 9)
    {
        cout << "NO" << endl;
        return 0;
    }

    vector<string> v;
    v.push_back("KIHBR");
    v.push_back("AKIHBR");
    v.push_back("KIHABR");
    v.push_back("KIHBAR");
    v.push_back("KIHBRA");
    v.push_back("AKIHABR");
    v.push_back("AKIHBAR");
    v.push_back("AKIHBRA");
    v.push_back("KIHABAR");
    v.push_back("KIHABRA");
    v.push_back("KIHBARA");
    v.push_back("AKIHABAR");
    v.push_back("AKIHABRA");
    v.push_back("AKIHBARA");
    v.push_back("KIHABARA");
    v.push_back("AKIHABARA");

    for (int i = 0; i < v.size(); i++)
        if (v[i] == s)
        {
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;
}
