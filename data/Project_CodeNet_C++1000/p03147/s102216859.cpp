#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    int hMax = 0;
    rep(i,n){
        cin >> h[i];
        hMax = max(hMax, h[i]);
    } 
    int ans = 0;
    for(int i = 1; i <= hMax; i++){
        bool ok = false;
        for (int j = 0; j < n; j++){
            if (h[j] >= i && !ok){
                ok = true;
            }
            else if (h[j] < i && ok){
                ok = false;
                ans++;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}