#include<iostream>
using namespace std;

int main(){
    //input
    long long N,M,Q;
    cin >> N >> M >>Q;
    long long i,j;
    long long L[M+1], R[M+1];
    long long p[Q+1], q[Q+1];
    for(i=1; i<=M; i++){
        cin >> L[i] >> R[i];
    }
    for(i=1; i<=Q; i++){
        cin >> p[i] >> q[i];
    }

    //calc
    long long single_sum[N+1][N+1];
    for(i=0; i<=N; i++){
        for(j=0; j<=N; j++){
            single_sum[i][j]=0;
        }
    }
    for(i=1; i<=M; i++){
        single_sum[L[i]][R[i]]++;
    }
    long long col_sum[N+1][N+1];
    for(j=0; j<=N; j++){
        for(i=0; i<=N; i++){
            col_sum[i][j]=0;
        }
    }
    for(j=0; j<=N; j++){
        for(i=0; i<=N; i++){
            col_sum[i][j]=0;
        }
    }
    for(j=1; j<=N; j++){
        for(i=1; i<=N; i++){
            col_sum[i][j]=col_sum[i-1][j]+single_sum[i][j];
        }
    }
    long long sum[N+1][N+1];
    for(i=0; i<=N; i++){
        for(j=0; j<=N; j++){
            sum[i][j]=0;
        }
    }
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            sum[i][j]=sum[i][j-1]+col_sum[i][j];
        }
    }
    //answer
    for(i=1; i<=Q; i++){
        cout << sum[N][q[i]] - sum[p[i]-1][q[i]] << endl;
    }
    system("pause");
    return 0;
}