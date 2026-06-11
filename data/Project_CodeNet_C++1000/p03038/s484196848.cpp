#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M; cin >> N >> M;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<int> B(M);
    vector<long long> C(M);
    for(int i = 0; i < M; i++) cin >> B[i] >> C[i];
    sort(A.begin(),A.end());
    vector<int> index(M);
    iota(index.begin(),index.end(),0);
    sort(index.begin(),index.end(),[&](int i,int j){
        return C[i] > C[j];
    });
    
    int cont = 0;
    for(auto i:index){
        for(int j = 0; j < B[i]; j++){
            if(A[cont] > C[i])break;
            A[cont] = C[i];
            cont++;
        }
    }
    long long sum = 0;
    for(int i = 0; i < N; i++) sum += A[i];
    cout << sum << endl;
    
    
    
    
}


