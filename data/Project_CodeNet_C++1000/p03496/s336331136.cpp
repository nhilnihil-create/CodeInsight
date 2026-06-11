#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};

int main(){
    ll n; cin >> n;
    vl a(n);
    ll mx = -inf;
    ll mn = inf;
    ll mxindex = 0;
    ll mnindex = 0;
    rep(i,n){
        cin >> a[i];
        if(mx<a[i]){
            mx = a[i];
            mxindex = i+1;
        }
        if(mn>a[i]){
            mn = a[i];
            mnindex = i+1;
        }
    }
    vpl ans;
    if(abs(mx)>abs(mn)){
        rep(i,n-1){
            while(a[i]>a[i+1]){
                ans.emplace_back(mxindex,i+2);
                a[i+1] += mx;
            }
            if(a[i+1]>mx){
                mx = a[i+1];
                mxindex = i+2;
            }
        }
    }else{
        for(ll i=n-1; i>0; i--){
            while(a[i]<a[i-1]){
                ans.emplace_back(mnindex,i);
                a[i-1] += mn;
            }
            if(a[i-1]<mn){
                mn = a[i-1];
                mnindex = i;
            }
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first << " " << i.second << endl;
    }
}
