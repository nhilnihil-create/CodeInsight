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
template<class T> inline int chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline int chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<29;
const ll LINF = 1LL<<58;
const int mod = 1000000007;

int check(int bits[25]){
    for (int i = 0; i < 20; i++) {
        if(bits[i] > 1) return 0;
    }
    return 1;
}

int main(){
    int n;
    cin >> n;
    int A[200010];
    for (int i = 0; i < n; i++) cin >> A[i];

    ll ans = 0;
    int bits[25] = {0}, flag = 0;
    int l = 0;
    
    for (int r = 1; r <= n; r++) {
        for (int j = 0; j < 20; j++) {
            bool bit = A[r - 1] & (1 << j);
            bits[j] += bit;
        }
        if(!check(bits)) flag = 1;

        while (flag) {
            for (int j = 0; j < 20; j++) {
                bool bit = A[l] & 1 << j;
                bits[j] -= bit;
            }
            if(check(bits)) flag = 0;
            l++;
        }

        ans += r-l;
    }

    cout << ans << endl;
    return 0;
}