#include <iostream>
#include <string>
using namespace std;
int x[501][501];
int c[501][501];
int main(void){
    int N,M,Q;
    cin >> N >> M >> Q;
    int L[M],R[M],p[Q],q[Q];
    for(int i=0;i<M;i++){
        cin >> L[i] >> R[i];
    }
    for(int i=0;i<Q;i++){
        cin >> p[i] >> q[i];
    }
    
    for(int i=0;i<M;i++){
        x[L[i]][R[i]]++;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            c[i][j] = x[i][j];
            if(j != 1){
                c[i][j] += c[i][j-1];
            }
        }
    }
    
    
    int ans = 0;
    for(int i=0;i<Q;i++){
        ans = 0;
        for(int j=p[i];j<=q[i];j++){
            ans += c[j][q[i]] - c[j][p[i]-1];
        }
        cout << ans << endl;
    }
    

}
