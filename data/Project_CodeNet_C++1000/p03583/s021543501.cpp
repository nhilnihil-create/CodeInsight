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
    bool m = true;
    for(ll i=1; i<3501; i++){
        if(m){
        for(ll j=1; j<3501; j++){
            if(m){
            if(4*i*j>=(i+j)*N){
            if(4*i*j-N*i-N*j != 0){
            if((N*i*j)%(4*i*j-N*i-N*j)==0){
                cout << i << " " << j << " " << (N*i*j)/(4*i*j-N*i-N*j);
                m = false;
            }
            }
            }
            }
        }
        }
    }
}