#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    int N, X; cin >> N >> X;
    vector<int> m(N);
    rep(i, N){
        cin >> m[i];
        X -= m[i];
    }
    sort(all(m));
    int ans = N;
    ans += X / m[0];
    cout << ans << endl;
}