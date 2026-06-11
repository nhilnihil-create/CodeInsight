#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t X,Y,Z,K;
    cin >> X >> Y >> Z >> K;
    vector<int64_t> A(X),B(Y),C(Z);
    for ( int64_t i = 0; i < X; ++i){
        cin >> A[i];
    }
    for ( int64_t i = 0; i < Y; ++i){
        cin >> B[i];
    }
    for ( int64_t i = 0; i < Z; ++i){
        cin >> C[i];
    }
    
    vector<int64_t> AB(X*Y);
    for ( int64_t i = 0; i < X; ++i){
        for ( int64_t j = 0; j < Y; ++j){
            int64_t ab = A[i] + B[j];
            AB[i*Y+j] = ab;
        }
    }
    sort(AB.begin(),AB.end(),greater<int64_t>());
    
    vector<int64_t> ABC(3000*Z);
    int64_t rep;
    if ( X * Y > 3000 ) rep = 3000;
    else rep = X * Y;
    for ( int64_t i = 0; i < rep; ++i){
        for ( int64_t j = 0; j < Z; ++j){
            int64_t abc;
            abc = AB[i] + C[j];
            ABC[i*Z+j] = abc;
        }
    }
    sort(ABC.begin(),ABC.end(),greater<int64_t>());
    
    for ( int64_t i = 0; i < K; ++i){
        cout << ABC[i] << endl;
    }
    
    
    return 0;
}
