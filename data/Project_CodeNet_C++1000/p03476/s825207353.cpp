#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

vector<bool> IsPrime;

void sieve(int max){
    IsPrime.assign(max, true);
    IsPrime[0] = false;
    IsPrime[1] = false;
    for(int i = 2; i*i <= max; i++){
        if(IsPrime[i]){
            for(int j = 2; i*j <= max; j++)IsPrime[i*j] = false;
        }
    }
}
int main(){
    sieve(100000);
    vector<int> sum(100001, 0);
    for(int i = 1; i <= 100000; i++){
        if(IsPrime[i] == true && IsPrime[(i + 1)/2] == true && i%2 == 1){
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
