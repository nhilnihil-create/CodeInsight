#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, M, Q;
    cin >> N >> M >> Q;
    int sta[N][N];
    for(int i=0; i<N; i++) fill(sta[i], sta[i] + N, 0);
    for(int i=0; i<M; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        sta[l][r] ++;
    }    
    int p[Q], q[Q];
    for(int i=0; i<Q; i++){
        cin >> p[i] >> q[i];
        p[i]--; q[i]--;
    }
    int sum[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==0) {
                sum[i][j] = sta[i][j];
                if(j != 0) sum[i][j] += sum[i][j-1];
            }
            else{
                if(j==0) sum[i][j] = sum[i-1][j] + sta[i][j];
                else sum[i][j] = sum[i-1][j] + sum[i][j-1] -sum[i-1][j-1] + sta[i][j];
            }
        }
    }
    for(int i=0; i<Q; i++){
        int ans = sum[q[i]][q[i]];
        if(p[i] != 0) ans -= sum[p[i] - 1][q[i]] - sum[q[i]][p[i] - 1] + sum[p[i]-1][p[i]-1];
        cout << ans << endl;
    }
    return 0;
}