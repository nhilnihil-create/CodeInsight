#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1 LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    int N;cin >> N;
    vector<int> a(N);rep(i,N)cin >> a[i];
    int ans = 0;
    int tmp = 1;
    rep(i,N){
        if(i == 0)continue;
        if(i == N-1){
            if(a[i] == a[i-1]){
                tmp++;
                ans += (tmp/2);
                break;
            }
            else{
                ans += (tmp/2);
                break;
            }
        }
        if(a[i] == a[i-1])tmp++;
        else{
            ans += (tmp/2);
            tmp = 1;
        }
    }

    cout << ans << endl;
}