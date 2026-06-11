#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,C;
    cin >> N >> M >> C;
    int B[M];
    for(int i=0; i<M; i++){
        cin >> B[i];
    }
    int A;
    int correct=0;
    double sum;
    for(int i=0; i<N; i++){
        sum=0;
        for(int j=0; j<M; j++){
            cin >> A;
            sum+=A*B[j];
        }
        sum+=C;
        if(sum>0){
            correct++;
        }
    }
    cout << correct << endl;
}
