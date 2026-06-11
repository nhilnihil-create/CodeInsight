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

const int INF = 1<<30;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> lv(n), rv(n);
    for(int i = 0; i < n; i++){
        if (s[i] == 'W') {
            if (i == 0) lv[i] = 1;
            else lv[i] = lv[i-1]+1;
        }
        else lv[i] = lv[i-1];
    }
    reverse(all(s));
    for(int i = 0; i < n; i++){
        if (s[i] == 'E') {
            if (i == 0) rv[i] = 1;
            else rv[i] = rv[i-1]+1;
        }
        else rv[i] = rv[i-1];
    }
    reverse(all(rv));
    int ans = INF;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        if (i-1 >= 0) cnt += lv[i-1];
        if (i+1 < n) cnt += rv[i+1];
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}