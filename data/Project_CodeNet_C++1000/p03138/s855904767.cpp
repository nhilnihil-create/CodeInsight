#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, j, n) for (int i = j; i < (int)(n); i++)
#define brep(i, n) for (int i = n; i > 0; i--)
#define BREP(i, j, n) for(int i = n; i > j; i--)
#define TEST cout << "PASS" << endl
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 1e6 + 1e3 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
    int n;
    cin >> n;
    ll k;
    cin >> k;
    ll a[100000], copy_a[100000];
    rep(i, n){
        cin >> a[i];
        copy_a[i] = a[i];
    }
    vector<int> v;
    rep(i, 40){
        int cnt = 0;
        rep(j, n){
            if(copy_a[j] & 1) cnt++;
            copy_a[j] >>= 1;
        }
        if(cnt <= (n-1)/2 && pow(2, i) <= k) v.push_back(i);
    }
    reverse(all(v));
    ll u = 0;
    for(int x: v){
        if(pow(2, x) + u <= k) u += pow(2, x);
    }
    ll ans = 0;
    rep(i, n){
        ans += u^a[i];
    }
    cout << ans << endl;

}