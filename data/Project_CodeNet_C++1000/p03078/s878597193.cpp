#include <bits/stdc++.h>
#define REP(i, n) for(long long i = 0; i < n; i++)
#define REPR(i, n) for(long long i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(long long i = m; i <= n; i++)
#define FORR(i, m, n) for(long long i = m; i >= n; i--)
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



int main(){FIN

    ll x,y,z,k; cin>>x>>y>>z>>k;
    vll a(x), b(y), c(z);

    REP(i,x) cin>>a[i]; REP(i,y) cin>>b[i]; REP(i,z) cin>>c[i];
    VSORTR(a); VSORTR(b); VSORTR(c);
    using T = tuple<ll,ll,ll,ll>;
    priority_queue<T> q;
    set<T> st;
    q.emplace(a[0]+b[0]+c[0], 0,0,0);

    REP(i,k){
        T tup = q.top();
        ll val = get<0>(tup);
        ll i1 = get<1>(tup);
        ll i2 = get<2>(tup);
        ll i3 = get<3>(tup);
        cout<<val<<endl;
        q.pop();
        
        T nx1, nx2, nx3;
        if(i1+1<x) nx1 = make_tuple(a[i1+1]+b[i2]+c[i3], i1+1,i2,i3);
        if(i2+1<y) nx2 = make_tuple(a[i1]+b[i2+1]+c[i3], i1,i2+1,i3);
        if(i3+1<z) nx3 = make_tuple(a[i1]+b[i2]+c[i3+1], i1,i2,i3+1);

        if(!st.count(nx1)){
            st.insert(nx1);
            q.push(nx1);
        }

        if(!st.count(nx2)){
            st.insert(nx2);
            q.push(nx2);
        }

        if(!st.count(nx3)){
            st.insert(nx3);
            q.push(nx3);
        }
  
    }

    return 0;
}