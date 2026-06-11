#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976
const double PI = 3.1415926535897932;

int cnt[200005];
int sm[200002];
int s[200002],t[200002],c[200002];

int main()
{
    int n,k; cin >> n >> k;
    vector<pair<int,P>> v(n);
    rep(i,n){
        cin >> s[i] >> t[i] >> c[i];
    }
    
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < 200002; j++) cnt[j] = 0;
        for(int j = 0; j < 200002; j++) if(c[j] == i) cnt[s[j]*2-1]++, cnt[t[j]*2]--;
        for(int j = 1; j < 200002; j++) cnt[j] += cnt[j-1];
        for(int j = 0; j < 200002; j++) if(cnt[j] > 0) sm[j]++;
    }
    int ans = 0;
    rep(i,200002) ans = max(ans,sm[i]);
    cout << ans << endl;
}