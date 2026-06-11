#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
const int MOD = 1000000007;
 
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int main(){
    ll n; cin >> n;
    ll a[n];
    ll nummax = 0;
    REP(i,n){
        cin >> a[i];
        nummax = max(nummax , a[i]);
    }
    ll b = -1;
    ll m = (long double)nummax/2.0;
    REP(i,n){
        if(abs(m-a[i]) < abs(m-b) && a[i] != nummax){
            b = a[i];
        }
    }
    cout << nummax << " " << b << endl;
    

}

