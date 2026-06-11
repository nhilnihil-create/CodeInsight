#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> B(n);
    rep(i, n) cin >> B[i];

    stack<int> ans;
    rep(i, n)
    {
        bool ok = false;
        for (int j = B.size() - 1; j >= 0; j--)
        {
            if (j + 1 == B[j])
            {
                ans.push(j + 1);
                B.erase(B.begin() + j);
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    rep(i, n)
    {
        cout << ans.top() << endl;
        ans.pop();
    }
}

//いわれてみれば確かにだが