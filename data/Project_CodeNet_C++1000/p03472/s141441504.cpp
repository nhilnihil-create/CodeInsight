#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    ll n, h;
    cin >> n >> h;

    vector<ll> a(n), b(n);
    rep(i, n){
        cin >> a.at(i) >> b.at(i);
    }

    sort(b.rbegin(), b.rend());
    ll amax = 0;
    rep(i, n){
        amax = max(amax, a.at(i));
    }

    ll cnt = 0;
    rep(i, n){
        if(amax>b.at(i)){
            break;
        }

        h -= b.at(i);
        cnt++;
        if(h<=0){
            break;
        }
    }

    if(h<=0){
        cout << cnt << endl;
    }
    else{
        ll tmp = (h+amax-1)/amax;
        cout << cnt + tmp << endl;
    }

    return 0;
}
