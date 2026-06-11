#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main() {
    ll N,H;
    cin >> N >> H;
    vector<ll> A,B;

    rep(i,N) {
        ll a,b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<ll>());
    ll a_max = A.back();
    ll t = 0;
    ll cnt = 0;
    rep(i,N) {
        if (B[i]>a_max) {
            t+=B[i];
            cnt++;
        }
        if (t>=H) {
            break;
        }
    }
    if (t>=H) {
        cout << cnt << endl;
    }
    else {
        while(1) {
            t+=a_max;
            cnt++;
            if (t>=H) {
                break;
            }
        }
        cout << cnt << endl;
    }

}
