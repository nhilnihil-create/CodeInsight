#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

ll f(int n){
    return (ll)n * n * n;
}

int main(){
    int n,k;
    cin >> n >> k;
    ll ans = 0;
    if(k%2!=0){
        ans = f(n/k);
    }else{
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(i%k==k/2) cnt++;
        }
        ans = f(n/k) + f(cnt);
    }
    cout << ans << endl;
}