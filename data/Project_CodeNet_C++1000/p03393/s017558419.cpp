#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;



int main(void)
{
    IOS
    const int N = 26;
    string S; cin >> S;
    set<char> st;
    REP(i,N) st.insert(i+'a');

    set<char> st1(st);
    for(auto c:S) st1.erase(c);
    string ans;
    if (st1.empty()) {
        set<char> st2;
        ans = S;
        st2.insert(ans.back());
        ans.pop_back();
        while(ans.size()) {
            char b = *st2.upper_bound(ans.back());
            if (ans.back() < b) {
                ans.back() = b;
                break;
            } else {
                st2.insert(ans.back());
                ans.pop_back();
            }
        }
        if (ans.empty()) ans = "-1";
    } else {
        ans = S + *st1.begin();
    }

    cout << ans << '\n';

    return 0;
}