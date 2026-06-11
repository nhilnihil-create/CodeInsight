#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, X;
    cin >> N >> X;
    vector<int> x(N);
    rep(i, N) cin >> x[i];
    vector<int> dist;
    rep(i, N){
        dist.push_back(abs(x[i] - X));
    }
    int ans = dist[0];
    rep(i, dist.size()){
        ans = __gcd(ans, dist[i]);
    }
    cout << ans << endl;
}   