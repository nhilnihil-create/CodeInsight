#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    int K;
    cin >> K;
    sort(all(a), greater<int>());
    rep(i, K){
        a[0] *= 2;
    }
    cout << a[0] + a[1] + a[2] << endl;
}