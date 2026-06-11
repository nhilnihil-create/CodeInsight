#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
#include <cassert>
using namespace std;
using ll = long long;
using plong = pair<ll,ll>;
ll MOD=998244353;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    ll A,B,C;
    cin>>A>>B>>C;
    ll res;
    if(A+B+1>=C){
        res = B+C;
    }else{
        res = A+B+1+B;
    }
    cout<<res<<endl;
    
}