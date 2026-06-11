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
    int N; cin >> N;
    vector<int> v(N,-1);

    auto q = [&](int i) {
        cout << i << endl;
        cout.flush();
        string s; cin >> s;
        if (s == "Male") v[i] = 1;
        else if (s == "Female") v[i] = 2;
        else v[i] = 0;
        return;
    };

    int l = 0;
    int r = N;
    q(0);
    if(v[0] == 0) return 0;
    int Q = 19;
    while(Q > 0) {
        int mid = (l+r) / 2;
        q(mid);
        if (v[mid] == 0) return 0;
        else {
            if ((mid-l) % 2 == 0) {
                if (v[mid] == v[l]) l = mid;
                else r = mid;
            } else {
                if (v[mid] == v[l]) r = mid;
                else l = mid;
            }
        }
        Q--;
    }

    return 0;
}
