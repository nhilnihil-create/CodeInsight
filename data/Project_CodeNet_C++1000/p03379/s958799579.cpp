#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const ll INF = 1e16;

void solver(int N, vector<ll> &A, vector<ll> &B){

    vector<ll> A_copy(N);
    A_copy = A;
    sort(A_copy.begin(), A_copy.end());

    int mid = N/2-1;

    for(int i=0; i<N; ++i){
        if(A.at(i) > A_copy.at(mid)){
            B.at(i) = A_copy.at(mid);
        }
        else{
            B.at(i) = A_copy.at(mid+1);
        }
    }
    return;
}

int main(){

    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; ++i){
        cin >> A.at(i);
    }

    vector<ll> B(N);
    solver(N, A, B);

    for(int i=0; i<N; ++i){
        cout << B.at(i) << endl;
    }
    return 0;
}
