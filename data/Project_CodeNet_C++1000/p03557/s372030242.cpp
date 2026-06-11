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
//ll calc_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        ++res;
//        N /= 10;
//    }
//    return res;
//}
//ll sum_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        res += N % 10;
//        N /= 10;
//    }
//    return res;
//}


int main(){
    int n; cin >> n;
    vector<int> a,b,c;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        b.push_back(x);
    }
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        c.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    ll ans = 0;
    for(int i = 0;i < n;i++){
        auto d = lower_bound(a.begin(),a.end(),b[i]);
        auto e = upper_bound(c.begin(),c.end(),b[i]);
        ans += (d-a.begin())*(n-(e-c.begin()));
    }
    cout << ans;
}

