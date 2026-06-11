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

ll tt(ll N, ll a, ll b, const vll &C, const vll &S, const vll &F){
    if(a == N-1){
        return b;
    }else{
        ll t = b;
        if(t >= S[a]){
            ll m = t % F[a];
            if(m == 0){
                tt(N, a+1, b+C[a], C, S, F);
            }else{
                tt(N, a+1, b+(F[a]-m)+C[a], C, S, F);
            }
        }else{
            tt(N, a+1, S[a]+C[a], C, S, F);
        }
    }
}

int main(){
    ll N; cin >> N;
    vll C(N-1), S(N-1), F(N-1);
    for(int i=0; i<N-1; i++){
        cin >> C[i] >> S[i] >> F[i];
    }
    for(int i=0; i<N; i++){
        cout << tt(N, i, 0, C, S, F) << endl;
    }
}