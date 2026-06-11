#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

const int NM = 1000;
int c[NM], s[NM], f[NM];
int ans[NM]; // [n] 駅を出発した列車

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    for(int i=1; i<=n-1; i++){
        cin>>c[i]>>s[i]>>f[i];
    }

    for(int station=1; station<=n; station++){
        for(int j=1; j<station; j++){ // すでに出発していた奴
            int dep = 0;
            if(ans[j] <= s[station-1]) dep = s[station-1]-ans[j];
            else dep = ((ans[j] - s[station-1] + (f[station-1]-1)) / f[station-1]) * f[station-1] + s[station-1] - ans[j];
            ans[j] = ans[j] + dep + c[station-1]; // 前の駅に到着した時間＋出発迄にかかる時間＋駅間
        }
        ans[station] = s[station]; // station 発射はs[station]時刻から。
    }
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<endl;
    }

}
// abc084_c.exe