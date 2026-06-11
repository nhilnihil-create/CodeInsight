#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    int K = 0,cnt = 1;
    for(;K < N;cnt++)K += cnt;
    if(K != N){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << cnt << endl;
    vector<int> V[cnt];
    int re = cnt-1,idx1 = 0,idx2 = 1;
    rep(i,1,N+1){
        V[idx1].push_back(i);
        V[idx2].push_back(i);
        if(idx2 == cnt-1){
            idx1++;
            idx2 = idx1 + 1;
        }else idx2++;
    }
    rep(i,0,cnt){
        cout << cnt - 1 << " ";
        rep(j,0,cnt-1)cout << V[i][j] << " \n"[j==cnt-2];
    }
}