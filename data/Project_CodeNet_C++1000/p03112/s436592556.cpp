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
    const ll LINF = 1LL << 60;
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> a(A), b(B);
    REP(i,A) cin >> a[i];
    REP(i,B) cin >> b[i];

    vector<ll> ab(A,LINF), ba(B,LINF);
    REP(i,A) {
        auto it = lower_bound(ALL(b),a[i]);
        if (it != b.end()) {  // a-b
            ab[i] = min(ab[i],abs(*it-a[i]));
        }
        if (it != b.begin()) { // b-a
            it--;
            ab[i] = min(ab[i],abs(a[i]-*it));
        }
    }
    REP(i,B) {
        auto it = lower_bound(ALL(a),b[i]);
        if (it != a.end()) {  // b-a
            ba[i] = min(ba[i],abs(*it-b[i]));
        }
        if (it != a.begin()) { // a-b
            it--;
            ba[i] = min(ba[i],abs(b[i]-*it));
        }
    }

    //vout(ALL(ab),cerr);
    //vout(ALL(ba),cerr);

    REP(i,Q) {
        ll X; cin >> X;
        ll ans = LINF;

        auto ita = lower_bound(ALL(a),X);
        int aidx = distance(a.begin(),ita);
        if (aidx != A) {
            ans = min(ans,abs(a[aidx]-X) + ab[aidx]);
        }
        if (aidx != 0) {
            ans = min(ans,abs(a[aidx-1]-X) + ab[aidx-1]);
        }

        auto itb = lower_bound(ALL(b),X);
        int bidx = distance(b.begin(),itb);
        if (bidx != B) {
            ans = min(ans,abs(b[bidx]-X) + ba[bidx]);
        }
        if (bidx != 0) {
            ans = min(ans,abs(b[bidx-1]-X) + ba[bidx-1]);
        }

        cout << ans << '\n';
    }


    return 0;
}