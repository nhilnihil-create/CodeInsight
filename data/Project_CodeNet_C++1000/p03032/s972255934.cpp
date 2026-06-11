#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define pb push_back

int main()
{
    ll N, K;
    cin >> N >> K;
    deque<ll> _D;
    REP(i,0,N) {
        ll v;
        cin >> v;
        _D.push_back(v);
    }

    ll m = -INF;
    REP(i,0,K+1) {
        REP(j,0,i+1) {
            REP(k,0,j+1) {
                ll a = i - j, b = j - k, c = k;
                deque<ll> D = _D;
                priority_queue<ll, vec, greater<ll>> Q;
                ll sum = 0;
                REP(l,0,a) {
                    if(D.empty()) break;
                    ll v = D.front();
                    D.pop_front();
                    Q.push(v);
                }
                REP(l,0,b) {
                    if(D.empty()) break;
                    ll v = D.back();
                    D.pop_back();
                    Q.push(v);
                }
                REP(l,0,c) {
                    if(Q.empty()) break;
                    ll v = Q.top();
                    Q.pop();
                }
                while(!Q.empty()) {
                    sum += Q.top();
                    Q.pop();
                }
                m = MAX(m,sum);
            }
        }
    }
    PR(m);



    return 0;
}

/*



*/