#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,clr;
    cin >> n >> clr;
    int d[clr][clr];
    for(int i = 0; i < clr; i++) {
        for(int j = 0; j < clr; j++) {
            cin >> d[i][j];
        }
    }
    int cnt[3][clr];
    fill(cnt[0],cnt[3],0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int r=(i+j)%3;
            int c;
            cin >> c;
            c--;
            cnt[r][c]++;
        }
    }

//    cout << "\n";
//    for(int i = 0; i < 3; i++) {
//        for(int j = 0; j < clr; j++) {
//            cout << cnt[i][j] << " ";
//        }
//        cout << "\n";
//    }
    if(n==1){
        cout << "0" << "\n";
        return 0;
    }
    int ans=1e9;
    int t[3];
    for(t[0] = 0; t[0] < clr; t[0]++) {
        for(t[1] = 0; t[1] < clr; t[1]++) {
            for(t[2] = 0; t[2] < clr; t[2]++) {
                if(t[0]==t[1]||t[1]==t[2]||t[2]==t[0]) continue;
                int tans=0;
                for(int l = 0; l < 3; l++) {
                    int to=t[l];
                    for(int m = 0; m < clr; m++) {
                        int fr=m;
                        int cost = d[fr][to]*cnt[l][fr];
                        tans+=cost;
                    }
                }
                ans=min(ans,tans);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}