#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N; cin >> N;
    vll A(N), B(N); vvll C(N, vll(2));
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i];
        C[i][0] = A[i] + B[i];
        C[i][1] = i;
    }
    sort(C.begin(),C.end());
    ll t=0, a=0;
    ll k = 0;
    for(int i=N-1; i>=0; i--){
        ll j = C[i][1];
        if(k%2==0){t+=A[j];}
        else{a+=B[j];}
        k++;
    }
    cout << t-a;
}