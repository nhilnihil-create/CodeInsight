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
    vll a(N);
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    map<ll, ll> m;
    vll lis(0);
    for(int i=0; i<N; i++){
        if(m.find(a[i]) == m.end()){
            m[a[i]] = 1;
            lis.emplace_back(a[i]);
        }else{
            m[a[i]]++;
        }
    }
    ll c = 0;
    for(auto x: lis){
        if(m[x] < x){
            c += m[x];
        }else{
            c += m[x] - x;
        }
    }
    cout << c;
}