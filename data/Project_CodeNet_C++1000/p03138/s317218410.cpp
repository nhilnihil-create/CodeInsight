#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, K, ans=0, tmp=0, dgt[42][2];
vector<ll> A;

signed main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
        int ct=0;
        while(a>=1) {
            ll a1 = a%2;
            dgt[ct][a1]++;
            a /= 2;
            ct++;
        }
    }
    for(int i=41;i>=0;i--) {
        if(K<pow(2,i)) continue;
        if(N-dgt[i][1]>dgt[i][1]) {
            tmp += pow(2,i);
            if(tmp>K) {
                tmp -= pow(2,i);
                //break;
            }
        }
    }
    for(int i=0;i<A.size();i++) {
        ans += A[i]^tmp;
    }
    //cout << tmp << " " << ans << endl;
    cout << ans << endl;
    return 0;
}