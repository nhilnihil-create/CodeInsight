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

// vector print(debug or stdout)
template <class Iit>
void vout(const Iit &begin,const Iit &end,ostream &out) {
    for(auto it = begin; it != end; it++) {
        auto tmp = it;
        if (++tmp == end) out << *it << '\n';
        else out << *it << " ";
    }
}

int main(void)
{
    IOS
    int N; cin >> N;
    list<int> B;
    REP(i,N) {
        int b; cin >> b;
        B.push_back(b);
    }

    vector<int> ans;
    REP(i,N) {
        // vout(ALL(ans),cerr);
        auto it = B.end(); it--;
        RREP(j,N-i) {
            if (j == 0) {
                OUT(-1)
                return 0;
            }
            if(*it == j) {
                ans.push_back(j);
                B.erase(it);
                break;
            }
            it--;
        }
    }
    reverse(ALL(ans));
    REP(i,N) OUT(ans[i])

    return 0;
}