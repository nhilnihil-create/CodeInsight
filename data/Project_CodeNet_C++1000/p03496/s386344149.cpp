#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long int ll;
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 移動方向

int n;
int a[51];

void input(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
}

bool check1(int* x, int n){
    for(int i=0;i<n;i++) if(*(x+i) < 0) return false;
    return true;
} //すべて0以上かどうかチェック

bool check2(int* x, int n){
    for(int i=0;i<n;i++) if (*(x+i) > 0) return false;
    return true;
} //すべて0以下かどうかチェック

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    vector<P> ans;
    if(check1(a, n)) for(int i=1;i<n;i++) ans.push_back(P(i, i+1));
    else if(check2(a, n)) for(int i=n;i>1;i--) ans.push_back(P(i, i-1));
    else{
        int mx = 0, mn = INF;
        int mx_num,mn_num;
        for(int i=0;i<n;i++) mx = max(mx, a[i]), mn = min(mn, a[i]);
        for(int i=0;i<n;i++){
            if(mx == a[i]) mx_num = i+1;
            else if(mn == a[i]) mn_num = i+1;
        }
        if(abs(mx) >= abs(mn)){
            for(int i=0;i<n;i++) ans.push_back(P(mx_num, i+1));
            for(int i=1;i<n;i++) ans.push_back(P(i, i+1));
        }
        else{
            for(int i=0;i<n;i++) ans.push_back(P(mn_num, i+1));
            for(int i=n;i>1;i--) ans.push_back(P(i, i-1));
        }
    }
    if(ans.empty()) cout << 0 << endl;
    else{
        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++) cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}