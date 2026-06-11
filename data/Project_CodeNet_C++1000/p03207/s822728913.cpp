#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    put(accumulate(p.begin(),p.end(),0) - *max_element(p.begin(),p.end()) / 2);
}