#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

bool isPrime(int x){
    int i;
    if(x < 2) return 0;
    else if(x == 2) return 1;
    if(x % 2 == 0) return 0;
    for(i = 3; i * i <= x; i += 2) if(x % i == 0)return 0;
    return 1;
}

int main(){
    vector<int> sum(100001, 0);
    for(int i = 1; i <= 100000; i++){
        if(isPrime(i) == true && isPrime((i + 1)/2) == true && i%2 == 1){
            sum[i] = sum[i - 1] + 1;
        }else sum[i] = sum[i - 1];
    }
    int Q; cin >> Q;
    vector<int> ans;
    rep(i, Q){
        int l, r; cin >> l >> r;
        l--;
        ans.push_back(sum[r] - sum[l]);
    }
    rep(i, Q) cout << ans[i] << endl;
}
