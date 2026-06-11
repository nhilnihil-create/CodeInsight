#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<int> a(n+2);
    a[0] = 0;
    a[n+1] = 0;

    rep(i,n) cin >> a[i+1];

    vector<int> difi(n+1);
    ll sum = 0;
    rep(i,n+1){
        difi[i] = abs(a[i+1] - a[i]);
        sum += difi[i];
    }

    rep(i,n){
        cout << sum - (abs(a[i+1] - a[i]) + abs(a[i+2] - a[i+1])) + abs(a[i+2] - a[i]) << endl;
    }
}
