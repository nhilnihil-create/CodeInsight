#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int N;
    cin >> N;
    ll F[N][10], P[N][11];

    //店Nが開いている時間帯
    for(int i=0; i<N; i++) for(int j=0; j<10; j++) cin >> F[i][j];
    //i:店N j:joisino共に開いている時間帯の個数
    for(int i=0; i<N; i++) for(int j=0; j<11; j++) cin >> P[i][j];

    ll res = -INF;
    for(int bit=1; bit<(1<<10); bit++) {
        ll cc = 0;
        for(int i=0; i<N; i++) {
            ll c = 0;
            for(int j=0; j<10; j++) {
                if((bit>>j&1) && (F[i][j] == 1)) c++;
            }
            cc += P[i][c];
        }
        if(res < cc) res = cc;
    }
    cout << res << endl;
}