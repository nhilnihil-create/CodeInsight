#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;

ll h,w;
ll a[505][505];

int main(){FIN
    cin>>h>>w;
    REP(i,h) REP(j,w) cin>>a[i][j];

    using T=tuple<ll,ll,ll,ll>;
    vector<T> move(0);
    REP(i,h){
        REP(j,w){
            if(a[i][j]%2!=0){
                if(j<w-1){
                    a[i][j]--; a[i][j+1]++;
                    move.push_back(make_tuple(i+1,j+1,i+1,j+2));
                }
                else if (j==w-1 && i<h-1){
                    a[i][j]--; a[i+1][j]++;
                    move.push_back(make_tuple(i+1,j+1,i+2,j+1));
                }

            }
        }
    }
    cout<<move.size()<<endl;
    for(auto p:move){
        cout<<get<0>(p)<<' '<<get<1>(p)<<' '<<get<2>(p)<<' '<<get<3>(p)<<endl;
    }
    return 0;
}