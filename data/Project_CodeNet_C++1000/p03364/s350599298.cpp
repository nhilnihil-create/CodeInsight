#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 1; i <= n; i++)
template<class T> inline int chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline int chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<29;
const ll LINF = 1LL<<58;
const int mod = 1000000007;

int n;
string table[310];

int check(int i){
    for (int y = 1; y < n; y++) {
        for (int x = i; x - i < y; x++) {
            if(table[y][x % n] != table[x - i][(y + i) % n]) return 0;
        }
    }
    return 1;
}


int main(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> table[i];
    int ans = 0;
    for (int i = 0; i < n; i++) ans += check(i) * n;
    cout << ans << endl;
    return 0;
}