#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M,C;
    cin>>N>>M>>C;
    vector<int> B(M);
    for(int i=0;i<M;i++){
        cin>>B[i];
    }
    int problemsSolved = 0;
    vector<int> A(M);
    for(int i=0;i<N;i++){
        int sum = 0;
        for(int i=0;i<M;i++){
            cin>>A[i];
            sum += A[i] * B[i];
        }
        if (sum > -C){
            problemsSolved++;
        }
    }
    cout<<problemsSolved<<endl;
}