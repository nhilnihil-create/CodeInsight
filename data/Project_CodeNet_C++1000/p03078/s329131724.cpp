#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll X,Y,Z,K;
    cin >> X >> Y >>Z >>K;
    vector<ll> A(X),B(Y),C(Z);
    for(int i=0;i<X;i++){
        cin >> A[i];
    }
    for(int i=0;i<Y;i++){
        cin >> B[i];
    }
    for(int i=0;i<Z;i++){
        cin >> C[i];
    }
    vector<ll> AB;
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            AB.push_back(A[i]+B[j]);
        }
    }
    sort(AB.rbegin(),AB.rend());
    sort(C.rbegin(),C.rend());
    vector<ll> ABK;
    for(int i=0;i<AB.size();i++){
        if(i>=K){
            break;
        }
        ABK.push_back(AB[i]);
    }
    vector<ll> ABC;
    for(int i=0;i<ABK.size();i++){
        for(int j=0;j<Z;j++){
            ABC.push_back(ABK[i] +C[j]);
        }
    }
    sort(ABC.rbegin(),ABC.rend());
    for(int i=0;i<K;i++){
        cout <<ABC[i] <<endl;
    }

    return 0;
}