#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M, C;
    cin >> N >> M >> C;

    vector<int>B(M);

    for(int i=0; i<M; i++){
        cin >> B[i];
    }

    vector<int>A(M);

    int A_sum=C, ans=0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> A[j];
            A_sum += A[j]*B[j];
        }
        if( A_sum > 0 ) ans++;
        A_sum = C;
    }

    cout << ans << endl;

    return 0;
}