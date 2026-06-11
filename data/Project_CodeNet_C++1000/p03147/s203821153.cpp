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
    vector<int> v;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        v.push_back(x);
    }
    vector<int> s; s.assign(v.size(),0);
    int ans = 0;
    int cnt = 0;
    while(true){
        cnt = 0;
        for(int i = 0;i < n;i++){
            if(v[i] != s[i]){
                for(int k = i;k < n;k++){
                    if(v[k] == s[k])break;
                    s[k]++;
                }
                ans++;
                break;
            }else{
                cnt++;
            }
        }
        if(cnt == n){
            break;
        }
    }
    cout << ans;
    
 }

