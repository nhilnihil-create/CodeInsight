#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    int A[110];
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }
    int M = A[0];
    int m = A[0];
    for (int i = 0; i < N; ++i)
    {
        if(A[i] > M){
            M = A[i];
        }
        if(A[i] < m){
            m = A[i];
        }
    }
    cout << M - m << endl;
}