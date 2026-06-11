#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//
int main(){
    char b; cin>>b;
    switch(b){
        
        case 'A': cout<<'T'<<endl; return 0;
        case 'T': cout<<'A'<<endl; return 0;
        case 'G': cout<<'C'<<endl; return 0;
        case 'C': cout<<'G'<<endl; return 0;

    }
}