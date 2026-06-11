#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


//void warshall_floyd(int n){
//    for(int k=0;k<n;k++){
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//            }
//        }
//    }
//}

int main() {
    int n; cin >> n;
    vector<ll>cnt = {0,0,0,0,0};
    int p[10] = {0,0,0,0,0,0,1,1,1,2};
    int q[10] = {1,1,1,2,2,3,2,2,3,3};
    int r[10] = {2,3,4,3,4,4,3,4,4,4};
    for(int i = 0;i < n;i++){
        string s;cin >> s;
        if(s[0] == 'M') cnt[0]++;
        if(s[0] == 'A') cnt[1]++;
        if(s[0] == 'R') cnt[2]++;
        if(s[0] == 'C') cnt[3]++;
        if(s[0] == 'H') cnt[4]++;
    }
    ll ans = 0;
    for(int i = 0; i < 10; ++i) {
      ans += cnt[p[i]] * cnt[q[i]] * cnt[r[i]];
    }
    cout << ans;
 }

