// 15:54-16:02
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int N, M, C;
    cin >> N >> M >> C;
    int B[M+1];
    rep1(i, M) cin >> B[i];
    int A[N+1][M+1];
    rep1(i, N) rep1(j, M) cin >> A[i][j];

    int ans = 0;
    int sum;

    rep1(i, N){
        sum = 0;
        rep1(j, M){
            sum += A[i][j] * B[j];
        }
        sum += C;

        if(sum > 0) ans++;
    }

    cout << ans << endl;

    return 0;
}