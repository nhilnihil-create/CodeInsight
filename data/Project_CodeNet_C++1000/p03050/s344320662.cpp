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
    ll ans = 0;
    ll p = 1;
    while(p*(p+1) < N){
        if((N-p)%p == 0){
            ans += (N-p)/p;
        }
        p++;
    }

    cout << ans;
}