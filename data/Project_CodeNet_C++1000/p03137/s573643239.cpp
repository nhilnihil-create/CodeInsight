#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    int N, M, A, B, C;
    string s1, s2;
    cin >> N >> M;
    vector<int> x(M);
    rep(i, M) cin >> x[i];
    if(M == 1){
        cout << 0 << endl;
        return 0;
    }
    sort(all(x));
    vector<pair<int, int>> dist(M - 1);
    rep(i, M - 1)dist[i] = make_pair(abs(x[i] - x[i + 1]), i);
    sort(all(dist), greater<pair<int, int>>());
    vector<bool> n(M, false);
    n[0] = true;
    rep(i, N - 1){
        if(i == M) break;
        n[dist[i].second + 1] = true;
    }

    ll ans = 0;
    int cnt = 0;
    int index = 0;
    rep(i, M){
        if(cnt == N) break;
        if(n[i] == true){
            cnt++;
            i++;
            while(n[i] == false && i < M){
                i++;
            }
            ans += x[i - 1] - x[index];
            index = i;
            i--;
        }
    }
    cout << ans << endl;
}