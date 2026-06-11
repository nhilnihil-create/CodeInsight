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
const ll inf = 1e15;



int main(){FIN
    using T = tuple<ll,ll,ll,ll>; 
    ll x,y,z,k;
    cin>>x>>y>>z>>k;
    vll a(x), b(y), c(z);
    REP(i,x) cin>>a[i];
    REP(i,y) cin>>b[i];
    REP(i,z) cin>>c[i];
    VSORTR(a); VSORTR(b); VSORTR(c);
    priority_queue<T> pq;
    map<T,ll> mp;
    pq.push(make_tuple(a[0]+b[0]+c[0],0,0,0));
    REP(i,k){
        T ans = pq.top();
        pq.pop();
        ll& sm= get<0>(ans);
        ll& i1 = get<1>(ans);
        ll& i2 = get<2>(ans);
        ll& i3 = get<3>(ans);
        // if(sm==18) cout<<i1<<i2<<i3<<endl;
        cout<<sm<<endl;
        T T1 = make_tuple(a[i1+1]+b[i2]+c[i3], i1+1,i2,i3);
        T T2 = make_tuple(a[i1]+b[i2+1]+c[i3], i1,i2+1,i3);
        T T3 = make_tuple(a[i1]+b[i2]+c[i3+1], i1,i2,i3+1);
        if (i1+1<x && !mp[T1]) {pq.push(T1); mp[T1]++;}
        if (i2+1<y && !mp[T2]) {pq.push(T2); mp[T2]++;}
        if (i3+1<z && !mp[T3]) {pq.push(T3); mp[T3]++;}

        

    }
    
    return 0;
}