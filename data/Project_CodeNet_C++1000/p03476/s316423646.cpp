#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const lli N = 1e5;

vector<bool> prime_table(lli x){
    vector<bool> p(x, true);
    if(x >= 0) p[0] = false;
    if(x >= 1) p[1] = false;
    for(int i = 2; i*i <= x; i++){
        if(!p[i]) continue;
        for(int j = i+i; j < x; j+=i){
            p[j] = false;
        }
    }
    return p;
}

lli q;

int main(void){
    cin >> q;
    auto pt = prime_table(N+10);
    vector<lli> s(N+5);
    for(int i = 1; i <= N; i++){
        s[i] = s[i-1];
        if(i%2 == 1 && pt[i] && pt[(i+1)/2]) s[i]++;
    }
    rep(i, q){
        lli l, r;
        cin >> l >> r;
        cout << s[r]-s[l-1] << endl;
    }
    return 0;
}
