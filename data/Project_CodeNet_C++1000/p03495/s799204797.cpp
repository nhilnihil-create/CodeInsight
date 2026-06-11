#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    set<int> s;
    rep(i, n) s.insert(a[i]);

    int ans = 0;
    vector<int> ck(200000, 0);
    rep(i, n) ck[a[i]]++;
    sort(all(ck));

    if (s.size() > k)
    {
        int num = s.size() - k;
        int i = 0;
        while (num)
        {
            if (ck[i] > 0)
            {
                num--;
                ans += ck[i];
            }
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
