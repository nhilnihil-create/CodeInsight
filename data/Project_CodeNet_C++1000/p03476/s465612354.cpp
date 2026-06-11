#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

vector<ll> V;

void prime(ll N){

bool C = 1;

    for(ll i = 2; i <= sqrt(N); i++){

    if(N%i == 0){C = 0;break;}
   
    }

if(C)V.push_back(N);

}

int main(){
ll Q;cin >> Q;
vector<ll> A;

rep(i, 2, 100000)prime(i);

//for(auto v : V )cout << v << endl;

rep(i, 0, V.size()){

    bool C = binary_search(ALL(V), (V[i] + 1)/2);

    if(C)A.push_back(V[i]);

}

rep(i, 1, Q + 1){

    ll l, r;cin >> l >> r;

    ll p = A.end() - lower_bound(ALL(A), l), q = A.end() - upper_bound(ALL(A), r);

    cout << p - q << endl;

}
}