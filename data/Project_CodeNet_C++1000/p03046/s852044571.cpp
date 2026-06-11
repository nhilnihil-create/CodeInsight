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

    ll m,k;cin>>m>>k;

    if(k >= pow(2,m)){
        cout<<-1<<endl;
        return 0;
    }

    else if (m==0) {
        cout<<0<<' '<<0<<endl; return 0;
    }
    else if(m==1 && k==0){
        cout<<0<<' '<<0<<' '<<1<<' '<<1<<endl; return 0;
    }



    else if(m>=2){
        FOR(i,0,pow(2,m)-1){
            if (i==k) continue;
            cout<<i<<' ';
        }
        cout<<k<<' ';
        FORR(i, pow(2,m)-1, 0){
            if (i==k)continue;
            cout<<i<<' ';
        }
        cout<<k<<endl;
        return 0;
    }

    cout<<-1<<endl;
    return 0;
}