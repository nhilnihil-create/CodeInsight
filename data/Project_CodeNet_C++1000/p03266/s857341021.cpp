#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

ll f(int a){
    return (ll)a*a*a;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    ll ans = 0;
    if(k%2==0){
        // n以下で、kの倍数および、kで割ってk/2余る個数
        ans = f(n/k);
        int cnt=0;
        while(cnt*k+k/2 <= n) cnt++;
        ans += f(cnt);
        // ans += f((n-k/2)/k+1);
        // cerr<<cnt<<endl;
        cerr<<(n-k/2)/k+1<<endl;
    } else {
        // n以下でkの倍数の個数
        ans = f(n/k);
    }
    cout<<ans<<endl;
}