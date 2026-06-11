#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    sum += abs(a[0]);
    rep(i,n-1){
        sum += abs(a[i+1] - a[i]);
    }
    sum += abs(a[n-1]);

    rep(i,n){
        if(i==0){
            cout << sum - (abs(0-a[0]) + abs(a[0] - a[1])) + abs(a[1]) << endl;
            continue;
        }else if(i==n-1){
            cout << sum - (abs(a[n-2] - a[n-1]) + abs(a[n-1])) + abs(a[n-2]) << endl;
            continue;
        }
        cout << sum - (abs(a[i-1] - a[i]) + abs(a[i] - a[i+1])) + abs(a[i+1] - a[i-1]) << endl;
    }
}