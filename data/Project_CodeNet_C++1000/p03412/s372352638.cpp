#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>


#define rep(i,n) for(int i = 0; i < n; i++)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

using namespace std;
using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;


ll bits[64];

int main(void){
    int n;
    vector<ll> a;
    vector<ll> b;

    cin >> n;
    a.resize(n);
    b.resize(n);
    for(auto &e: a)cin >> e;
    for(auto &e: b)cin >> e;
    sort(all(b));
    ll T = 1, p = 2;
    rep(bit, 31){
        vector<ll> bp = b;
        rep(i, n)bp[i]%=p;
        sort(all(bp));
//         cout << "-------- " << bit << endl; 
//         rep(i,n) cout << bp[i] << " ,";
//         cout << endl;
        rep(j, n){
            ll ap = a[j]%p;

            // [p-ap, 2*p-ap), [3*p-ap, 4*p-ap)内のbpの数が偶数or奇数
//             cout << "---- " << ap  << " " << T << " " << 1*T-ap << " " << 2*T-ap << " " << 3*T-ap << " " << 4*T-ap<< endl;
//             cout << (lower_bound(bp.begin(), bp.end(), 2*T-ap)-bp.begin()) << " - " << (lower_bound(bp.begin(), bp.end(), 1*T-ap)-bp.begin()) << endl;
//             cout << (lower_bound(bp.begin(), bp.end(), 4*T-ap)-bp.begin()) << " - " << (lower_bound(bp.begin(), bp.end(), 3*T-ap)-bp.begin()) << endl;
            ll cnt = (lower_bound(bp.begin(), bp.end(), 2*T-ap)-bp.begin()) - (lower_bound(bp.begin(), bp.end(), 1*T-ap)-bp.begin());
            cnt += (lower_bound(bp.begin(), bp.end(), 4*T-ap)-bp.begin()) - (lower_bound(bp.begin(), bp.end(), 3*T-ap)-bp.begin());
            bits[bit]+=cnt;
        }
        T*=2;
        p*=2;
    }

    ll ans = 0;
    ll z = 1;
    rep(i, 32){
        if(bits[i]%2==1) ans += z;
        z*=2;
    }
    cout << ans << endl;

    return 0;
}

