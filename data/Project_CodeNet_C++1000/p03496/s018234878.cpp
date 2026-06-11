#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

const ll INF=1LL << 58;
ll N,n_minus,n_plus,ma,mi;
vector<ll> a;
vector<PLL> ops;
signed main() {
    cin>>N;
    a.resize(N);
    ma = 0;
    mi = 0;
    rep(i,0,N){
        cin>>a[i];
        if (a[i]>=0) n_plus++;
        else n_minus++;

        if (a[i] > a[ma]) ma = i;
        if (a[i] < a[mi]) mi = i;
    }

    if (n_plus > 0 && n_minus > 0){
        if (a[ma] > -a[mi]){
            rep(i,0,N) {
                a[i] += a[ma];
                ops.push_back(PLL(ma, i));
                n_plus = N;
                n_minus = 0;
            }
        }else{
            rep(i,0,N) {
                a[i] += a[mi];
                ops.push_back(PLL(mi, i));
                n_plus = 0;
                n_minus = N;
            }
        }
    }

    if (n_plus > 0){
        rep(i,1,N){
            ops.push_back(PLL(i-1,i));
            a[i] += a[i-1];
        }
    } else {
        for (ll i=N-2; i>=0; i--){
            ops.push_back(PLL(i+1,i));
            a[i] += a[i+1];
        }
    }
    cout<<ops.size()<<endl;
    for(auto e: ops)
        cout<<e.first+1<<" "<<e.second+1<<endl;

    // cout<<"res: ";
    // for(auto e: a) cout<<e<<" ";
    // cout<<endl;

    return 0;
}
