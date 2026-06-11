#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    int C;
    cin >> C;
    vector<vector<int> > televi(100002, vector<int>(C + 1));
    rep(i,100002){
        rep(j,C + 1){
            televi[i][j] = 0;
        }
    }
    rep(i,N){
        int s,t,c;
        cin >> s >> t >> c;
        televi[s][c]++;
        televi[t + 1][c]--;
    }
    rep(i,100001){
        rep(j,C + 1){
            televi[i + 1][j] += televi[i][j];
        }
    }
    vector<int> sametime(100002, 0);
    rep(i,100002){
        rep(j,C + 1){
            if (televi[i][j] >= 1) sametime[i]++;
        }
    }
    int ans = 0;
    rep(i,100002){
        ans = max(ans, sametime[i]);
    }
    cout << ans << endl;
}