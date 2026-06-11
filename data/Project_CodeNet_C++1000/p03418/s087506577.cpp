#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll N, K;
    cin >> N >> K;
    ll sum = 0;
    for(ll i=K+1;i<=N;i++){
        ll q = N/(i);
        ll r = N%(i);
        r = max(r-K+1,ll(0));
        if(K == 0) r--;
        sum += q*(i-K) + r;
        //cout << q*(i-K) + r << " ";
    }
    //cout << endl;

    cout << sum << endl;
}
