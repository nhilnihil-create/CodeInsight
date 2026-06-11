#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, M; cin >> N >> M;
    vector<vector<int>> lights(M);
    rep(i, M){
        int k; cin >> k;
        rep(j, k){
            int s; cin >> s;
            lights[i].push_back(s - 1);
        }
    }
    vector<int> p(M);
    rep(i, M) cin >> p[i];
    ll ans = 0;
    for(int i = 0; i < (1 << N); i++){
        bitset<10> s(i);
        bool flag = true;
        rep(i, M){
            int tmp = 0;
            rep(j, lights[i].size()) tmp += s.test(lights[i][j]);
            if(tmp%2 != p[i]){
                flag = false;
                break;
            }
        }
        if(flag == true) ans++;
    }
    cout << ans << endl;
} 