#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int dist[10][10];
void warshall_floyd(int n){
    rep(k,n)rep(i,n)rep(j,n){
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }
}

int main(){
    int h, w;
    cin >> h >> w;
    rep(i,10)rep(j,10) cin >> dist[i][j];
    int A[h][w];
    rep(i,h)rep(j,w) cin >> A[i][j];

    int ans = 0;
    warshall_floyd(10);
    rep(i,h)rep(j,w){
        if (A[i][j] == -1) continue;
        ans += dist[A[i][j]][1];
        //printf("%d\n", dist[A[i][j]][1]);
    }
    // rep(i,10){
    //     rep(j,10){
    //         printf("%d ", dist[i][j]);
    //     }
    //     printf("\n");
    // }

    cout << ans << endl;
    return 0;
}
