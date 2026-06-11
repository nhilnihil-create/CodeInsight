#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, A, B; cin >> N >> A >> B;
    long long seki = (long long)A*B;
    if(seki < (long long)N || N < A+B-1 ) {cout << -1 << endl; return 0;}
    if(B==1){
        for(int i=0; i<N; i++){
            cout << i+1 << " ";
        }
        cout << endl;
        return 0;
    }
    if(A==1){
        for(int i=0; i<N; i++){
            cout << N-i << " ";
        }
        cout << endl;
        return 0;
    }
    int q = (N-A)/(B-1);
    int r = (N-A)%(B-1);
    for(int i=0; i<q; i++){
        for(int j=0; j<B; j++){
            cout << i*B+B-j << " ";
        }
    }
    if(q==A) { cout << endl; return 0;}
    for(int i=r+1; i>=1; i--){
        cout << q*B+i << " ";
    }
    for(int i=q*B+r+2; i<=N; i++){
        cout << i << " ";
    }
    cout << endl;
}