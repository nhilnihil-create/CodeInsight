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
using PQ = priority_queue<P,vector<P>,greater<P>>;

int main(){
    ll n,h;
    cin >> n >> h;
    P a[n],b[n];
    vector<P> vec;

    rep(i,0,n){
        cin >> a[i].fs >> b[i].fs;
        a[i].sc = i;
        b[i].sc = i;
    }

    sort(a,a+n,greater<P>());
    sort(b,b+n,greater<P>());

    ll cnt = 0;

    rep(i,0,n){
        if(a[0].fs <= b[i].fs){
            h -= b[i].fs;
            cnt++;
        }

        if(h <= 0){
            cout << cnt << endl;
            return 0;
        }
    }


    cnt += ceil((double)h/(double)a[0].fs);
    
    cout << cnt << endl;
    return 0;
}