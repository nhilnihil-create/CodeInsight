#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

const int NM = 110;
int f[NM][10];
int p[NM][11];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;

    rep(i,n){
        rep(j, 10){
            cin >> f[i][j];
        }
    }
    rep(i, n){
        rep(j, 11){
            cin>>p[i][j];
        }
    }
    // bit全探索
    ll ans = -1e15;
    for(int bit=1; bit<(1<<10); bit++){
        // このパターンにおける共通Openの数をカウントする
        ll score = 0;
        for(int j=0; j<n; j++){ // 店Jに対して
            int cnt = 0;
            for(int i=0; i<10; i++){
                if(bit & (1<<i)){
                    if(f[j][i] == 1){
                        cnt++;
                    }
                }
            }
            score += p[j][cnt];
        }
        ans = max(ans, score);
    }
    cout<<ans<<endl;

}

// abc080_c