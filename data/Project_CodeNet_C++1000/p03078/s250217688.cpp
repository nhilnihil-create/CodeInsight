#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//入力
ll X,Y,Z,K;
vector<ll> A(X);
vector<ll> B(Y);
vector<ll> C(Z);
vector<ll> ans;

int main(){
    cin >> X >> Y >> Z >> K;
    A.assign(X,0);
    B.assign(Y,0);
    C.assign(Z,0);
    for(int i=0; i<X; i++) cin >> A[i];
    for(int i=0; i<Y; i++) cin >> B[i];
    for(int i=0; i<Z; i++) cin >> C[i];

    vector<ll> A_B(X*Y);
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            A_B.push_back(A[i]+B[j]);
        }
    }

    sort(A_B.begin(),A_B.end());

    vector<ll> A_B_C(K*Z);
    for(int i=1; i<=K; i++){
        for(int j=0; j<Z; j++){
            A_B_C.push_back(A_B[A_B.size()-i] + C[j]);
        }
    }

    sort(A_B_C.begin(),A_B_C.end());

    for(int i=1; i<=K; i++){
        cout << A_B_C[A_B_C.size() - i] << endl;
    }
}