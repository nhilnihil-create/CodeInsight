#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


struct TV{
    int s,t,c;
    bool operator<(const TV &o) const{
        return t < o.t;
    }
};

int main() {
    int N,C; cin >> N >> C;

    vector<vector<int>> tv(C+1,vector<int>(100100,0));

    REP(i,N){
        int s,t,c; cin >> s >> t >> c;
        tv[c][s] += 1;
        tv[c][t+1] -= 1;
    }

    REP(i,C+1){
        REP(j,100010){
            tv[i][j+1] += tv[i][j];
        }
    }

    int ans = 0;
    REP(j,100010){
        int cnt = 0;
        REP(i,C+1){
            if(tv[i][j]>0)cnt++;
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;

    // vector<TV> T(N);
    // REP(i,N) cin >> T[i].s >> T[i].t >> T[i].c;
    
    // sort(ALL(T));

    // int ans = 0;
    
    // //チェック済みならc = -1
    // while(1){
    //     int before = 0;
    //     int before_c = 0;
    //     int cnt = 0;
    //     REP(i,N){
    //         if(T[i].c==-1){
    //             cnt++;
    //             continue;
    //         }

    //         if(before < T[i].s){
    //             before = T[i].t;
    //             before_c = T[i].c;
    //             T[i].c = -1;
    //         }else if(before==T[i].s && before_c==T[i].c){
    //             before = T[i].t;
    //             before_c = T[i].c;
    //             T[i].c = -1;
    //         }else{
    //             cnt++;
    //         }
    //     }
    //     if(cnt == N) break;
    //     ans++;
    // }

    // cout << ans << endl;


    return 0;
}