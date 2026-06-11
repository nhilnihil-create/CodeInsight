#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

bool is_prime[1000010];


int main() {
    int n,ba = 0,b = 0,a = 0,ans = 0;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i].size()-1; ++j) {
            if(s[i][j] == 'A' && s[i][j+1] == 'B') ans++;
        }
        if(s[i][0] == 'B' && s[i][s[i].size()-1] == 'A') ba++;
        else if(s[i][0] == 'B') b++;
        else if(s[i][s[i].size()-1] == 'A') a++;
    }
    int mn = min(a,b),mx = max(a,b);
    if(ba == 0){
        ans += mn;
    }else{
        if(a+b == 0) ans += (ba-1);
        else {
            ans += ba+mn;
        }
    }
    cout << ans << endl;
    return 0;
}