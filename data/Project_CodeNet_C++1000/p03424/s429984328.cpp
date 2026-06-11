#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    set<char>st;
    while(n--)
    {
        char x;
        cin >> x;
        st.insert(x);
    }
    cout << (st.size() == 3 ? "Three" : "Four");
    return 0;
}
