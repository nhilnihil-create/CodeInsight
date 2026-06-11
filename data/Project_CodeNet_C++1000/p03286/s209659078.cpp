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



int main(){FIN

    ll n; cin>>n;
    if (n==0) {cout<<0<<endl; return 0;}
    vll a(0); vll b(0);
    while (n!=0){
        if ((inf + n)%4==1){
            a.push_back(1);
            b.push_back(0);
            n -= 1;
        }
        else if((inf + n)%4==3){
            a.push_back(1);
            b.push_back(1);
            n += 1;
        }
        else if((inf + n)%4==2){
            a.push_back(0);
            b.push_back(1);
            n += 2;
        }
        else{
            a.push_back(0);
            b.push_back(0);
            n += 0;
        } 
        n /= 4;
    }

    reverse(ALL(a));
    reverse(ALL(b));
    if(b[0] != 0){
        REP(i,a.size()) cout<<b[i]<<a[i];
    }
    else{
        cout<<a[0];
        REP(i,a.size()-1) cout<<b[i+1]<<a[i+1];
    }
    return 0;
}