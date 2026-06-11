#include <iostream>
using namespace std;

int main(){
    int N,M;
    int C;
    cin >> N >> M;
    cin >> C;
    int A;
    int B[25];
    int i,j;

    for(i=0; i<M; i++){
        cin >> B[i];
    }

    int value;
    int count=0;

    for(i=0; i<N; i++){
        value=0;
        for(j=0; j<M; j++){
            cin >> A;
            value+=A*B[j];
        }   
        if(value+C>0) count++;
    }

    cout << count << endl;

    return 0;
}