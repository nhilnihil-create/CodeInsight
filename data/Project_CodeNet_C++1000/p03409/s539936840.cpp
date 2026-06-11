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
    vector<pair<int,int>> r(n),b(n);
    rep(i,n)cin >> r[i].first >> r[i].second;
    rep(i,n)cin >> b[i].second >> b[i].first;
    vector<bool> used(n,0);
    sort(ALL(r),greater<>());
    sort(ALL(b));
    rep(i,n)swap(b[i].first,b[i].second);
    int ans = 0;
    rep(i,n){
        rep(j,n){
            if(r[i].first < b[j].first && r[i].second < b[j].second && !used[j]){
                ans++;
                used[j] = 1;
                break;
            }
        }
    }
    cout << ans << endl;
}