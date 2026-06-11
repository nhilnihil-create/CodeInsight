#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    vector<int> a(3);
    rep(0, i, 3)
    {
        cin >> a[i];
    }
    sort(all(a));
    cout << a[0] + a[1] + a[2] * 10 << endl;
}