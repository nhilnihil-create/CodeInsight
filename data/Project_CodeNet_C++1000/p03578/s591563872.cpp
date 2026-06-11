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
    vll D(N); 
    for(int i=0; i<N; i++){
        cin >> D[i];
    }
    ll M; cin >> M;
    vll T(M);
    for(int i=0; i<M; i++){
        cin >> T[i];
    }
    sort(D.begin(),D.end());
    sort(T.begin(),T.end());
    ll d = 0;
    map<ll, ll> m;
    map<ll, ll> n;
    vll s(0);
    for(int i=0; i<M; i++){
        if(m.find(T[i]) == m.end()){
            m[T[i]] = 1;
            s.emplace_back(T[i]);
        }else{
            m[T[i]]++;
        }
    }
    for(int i=0; i<N; i++){
        if(n.find(D[i]) == n.end()){
            n[D[i]] = 1;       
        }else{
            n[D[i]]++;
        }
    }
    bool t = true;
    for(auto x: s){
        if(n.find(x) == n.end()){
            t = false;
        }else if(m[x] > n[x]){
            t = false;
        }
    }
    if(t){cout << "YES";}
    else{cout << "NO";}
}