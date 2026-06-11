#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, M, Q;
    cin >> N >> M >> Q;

    int L[M], R[M];
    for(int i=0; i<M; i++){
        cin >> L[i] >> R[i];
    }

    int p[Q], q[Q];
    for(int i=0; i<Q; i++){
        cin >> p[i] >> q[i];
    }

    int sum[N+1][N+1];
    for(int i=0; i<N+1; i++){
        for(int j=0; j<N+1; j++){
            sum[i][j] = 0;
        }
    }

    for(int i=0; i<M; i++){
        sum[L[i]][R[i]]++;
    }

    for(int i=0; i<=N; i++){
        for(int j=0; j<N; j++){
            sum[i][j+1] += sum[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<=N; j++){
            sum[i+1][j] += sum[i][j];
        }
    }

    for(int i=0; i<Q; i++){
        int s = p[i];
        int e = q[i];

        int ans = sum[e][e] + sum[s-1][s-1] - sum[s-1][e] - sum[e][s-1];
        cout << ans << endl;
    }

    return 0;
}
