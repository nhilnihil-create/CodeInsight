#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int t[105][10];
int score[105][11];

int main(){
    int n;
    cin >> n;
    rep(i,n)rep(j,10) cin >> t[i][j];
    rep(i,n)rep(j,11) cin >> score[i][j];

    int ans = -1e9;
    rep(sche,1<<10){
        if(sche==0) continue;
        int sum = 0;
        rep(i,n){
            int cnt = 0;
            rep(j,10) {
                //cout << (sche>>j&1) << endl;
                if(sche>>j&1 == t[i][j]) cnt++;
            }
            sum += score[i][cnt];
            //cout << cnt << endl;
        }
        ans = max(ans,sum);
    }

    cout << ans << endl;
}