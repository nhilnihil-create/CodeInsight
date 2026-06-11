#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(void){
    int N,M,C;
    cin >> N >> M >>C;
    int B[M],A[N][M];
    for(int i=0;i<M;i++){
        cin >> B[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> A[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        int sum = 0;
        for(int j=0;j<M;j++){
            sum += B[j]*A[i][j];
        }
        if(sum + C > 0){
            ans++;
        }
    }
    
    cout << ans << endl;
}
