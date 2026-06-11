#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<pair<double,int>> a(n);
    double sum = 0;
    rep(i,n){
        cin >> a[i].first;
        sum += a[i].first;
        a[i].second = i;
    }
    sum/= n;
    double dis = 1e18;
    int ans = 0;
    rep(i,n){
        if(dis > abs(sum-a[i].first)){
            dis = abs(sum-a[i].first);
            ans = a[i].second;
        }
    }
    cout << ans << endl;
}