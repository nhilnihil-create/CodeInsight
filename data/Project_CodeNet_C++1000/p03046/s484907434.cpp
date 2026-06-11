#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;

int main(){
    ll m,k;
    cin >> m >> k;
    if(pow(2,m) <= k){
        cout << -1 << endl;
    }
    else if(m == 1){
        if(k == 0) cout << "0 0 1 1" << endl;
        else cout << "-1" << endl;
    }
    else{
        cout << k << " ";
        rep(i,0,pow(2,m)){
            if(i == k) continue;
            cout << i << " ";
        }
        cout << k << " ";
        rep(i,0,pow(2,m)){
            if(pow(2,m) - i - 1 == k) continue;
            cout << pow(2,m) - i - 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
