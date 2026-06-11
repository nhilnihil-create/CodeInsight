#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli a, b;

lli sumxor(lli n){
    if(n%4 == 0) return n;
    else if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else return 0;
}

int main(void){
    cin >> a >> b;
    lli u, v;
    u = sumxor(a-1);
    v = sumxor(b);
    cout << (u^v) << endl;
    return 0;
}
