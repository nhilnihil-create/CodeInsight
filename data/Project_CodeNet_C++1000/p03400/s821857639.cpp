#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, D, X;
    cin >> N >> D >> X;
    int ans = X;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    for(int i = 0; i < D; i++){
        for(int j = 0; j < N; j++){
            if(a[j] * i + 1 <= D) ans++;
        }
    }
    cout << ans << endl;
}