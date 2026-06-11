#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, X;
    cin >> N >> M >> X;
    int A[M];
    for(int i=0; i<M; i++){cin >> A[i];}

    int cost1 = 0;
    int cost2 = 0;
    for(int i=0; i<M; i++){
        if(A[i] < X){
            cost1 += 1;
        } else {
            cost2 += 1;
        }
    }

    int ans = (cost1 > cost2)? cost2 : cost1;
    cout << ans << endl;
    return 0;
}