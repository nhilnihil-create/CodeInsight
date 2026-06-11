#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define N 100
int main() {
    int a, b; cin >> a >> b;
    a--, b--;
    char g[N][N];
    rep(i, N/2) {
        rep(j, N) g[i][j] = '#';
    }
    rep(i, N/2) {
        rep(j, N) g[N/2+i][j] = '.';
    }
    //::::::::::::::::::::::::::::
    int cnt = 0;
    for(int i=0; i<N/2; i+=2) {
        int j = (i%2==0)?0:1;
        while(cnt < a) {
            g[i][j] = '.';
            j += 2;
            cnt++;
            if(j>=N) break;
        }
        if(cnt == a) break;
    }
    //::::::::::::::::::::::::::::
    cnt = 0;
    for(int i=N-1; i>=N/2; i-=2) {
        int j = (i%2==0)?1:0;
        while(cnt < b) {
            g[i][j] = '#';
            j += 2;
            cnt++;
            if(j>=N) break;
        }
        if(cnt == b) break;
    }
    //::::::::::::::::::::::::::::
    printf("%d %d\n",N,N);
    rep(i, N) {
        rep(j, N) {
            cout << g[i][j];
        }puts("");
    }
}
