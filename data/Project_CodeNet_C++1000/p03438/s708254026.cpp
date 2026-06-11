#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;


const ll MOD = 1e9+7;


signed main(){
    ll n;
    cin >> n;
    ll a[n],b[n],sum_a = 0,sum_b = 0,cnt1 = 0,cnt2 = 0;
    rep(i,0,n){
        cin >> a[i];
        sum_a += a[i];
    }
    rep(i,0,n){
        cin >> b[i];
        sum_b += b[i];

        if(a[i] < b[i]){
            cnt2 += ceil((double)(b[i] - a[i])/2.0);
        }
        else if(a[i] > b[i]){
            cnt1 += a[i] - b[i];
        }
    }

    if(cnt1 <= sum_b - sum_a && cnt2 <= sum_b - sum_a){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }


    return 0;
}
