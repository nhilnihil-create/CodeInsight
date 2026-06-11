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
    int N; cin >> N;
    vector<int> T(3);
    REP(i,3) cin >> T[i];
    vector<int> L(N);
    REP(i,N) cin >> L[i];

    int ans = 1 << 30;
    vector<int> use(N);
    bool loop = true;
    while(loop) {
        int tmp = 0;
        vector<int> l(3);
        vector<int> connect(3);
        REP(i,N) {
            if (use[i] != 3) {
                l[use[i]] += L[i];
                connect[use[i]]++; 
            }
        }
        REP(i,3) {
            if (connect[i] == 0) {
                tmp = 1<< 30; 
                break;
            }
            tmp += abs(T[i] - l[i]) + (connect[i] -1) * 10;
        }
        if (ans > tmp) {
            ans = min(ans,tmp);
            //cerr << ans << " ";
            //vout(ALL(use),cerr);
        }
        use[0]++;
        REP(i,N) {
            if (use[i] == 4) {
                if (i == N-1) {
                    loop = false;
                } else {
                    use[i] = 0;
                    use[i+1]++;
                }
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}