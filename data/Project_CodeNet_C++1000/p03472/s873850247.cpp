#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    ll N, H;
    cin >> N >> H;
    vector<ll> p1(N), p2(N);
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        p1[i] = a;
        p2[i] = b;
    }
    sort(all(p1), greater<ll>());
    sort(all(p2), greater<ll>());
    ll firstMax = p1[0];
    ll count = 0;
    rep(i, N){
        if(p2[i] < firstMax) break;
        H -= p2[i];
        count++;
        if(H <= 0){
            H = 0;
            break;
        }
    }
    cout << count + (H + p1[0] - 1) / p1[0] << endl;
}