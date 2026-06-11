#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi pre;
    pre.pb(0);

    for(int i = 0; i < n; ++i)
    {
        int pro = pre.back();
        if(s[i] == 'C')
        {
            if(i-1 >= 0 && s[i-1] == 'A')
                ++pro;
        }
        pre.pb(pro);
    }

    for(int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        int ans = pre[r] - pre[l-1];

        if(s[l-1] == 'C')
        {
            if(l-2 >= 0 && s[l-2] == 'A')
                --ans;
        }

        cout << ans << '\n';
    }
}
