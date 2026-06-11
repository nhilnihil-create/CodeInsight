#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define fi first
#define se second
#define pb push_back
#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 1e5 + 10;
const int oo = 1e18;

int n, a, b;

signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false); cout.tie(0);
    string x, y, z;
    cin >> n >> x >> y >> z;

    int sum = 0;
    FOR(i, 0, n - 1)    {
        set<char> st;
        st.insert((char)(x[i]));
        st.insert((char)(z[i]));
        st.insert((char)(y[i]));
        if(st.size() == 3) sum += 2;
        if(st.size() == 2) sum += 1;
    }
    return cout << sum, 0;
}
