#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 30;
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int ba = 0, a = 0, b = 0;
    rep(i,n){
        string s;
        cin >> s;
        for(int j = 0; j < sz(s)-1; j++){
            if (s[j] == 'A' && s[j+1] == 'B') ans++;
        }
        if (s[0] == 'B' && s[sz(s)-1] == 'A') ba++;
        else if (s[0] == 'B') b++;
        else if (s[sz(s)-1] == 'A') a++;
    }
    if (ba == 0){
        ans += min(a, b);
    }else{
        if (a == 0 && b == 0){
            ans += ba-1;
        }else{
            ans += ba;
            ans += min(a, b);
        }
    }
    cout << ans << endl;
}