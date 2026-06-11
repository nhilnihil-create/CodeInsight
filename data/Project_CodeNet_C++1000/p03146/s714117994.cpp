#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)

#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

int main(void)
{
    int s;
    cin >> s;
    vector<int> a;
    a.push_back(s);
    set<int> st;
    st.insert(s);
    bool flag = true;
    int cta = 1;
    int ans = 0;
    while (flag)
    {
        int tmp = a.back();
        if (tmp % 2 == 0)
            tmp /= 2;
        else
            tmp = 3 * tmp + 1;
        a.push_back(tmp);
        if (find(all(st), tmp) != st.end())
            flag = false;
        st.insert(tmp);
        ++cta;
    }
    ans = cta;
    cout << ans << endl;
}
