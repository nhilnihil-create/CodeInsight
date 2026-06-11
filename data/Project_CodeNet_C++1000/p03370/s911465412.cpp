#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int n, x; cin >> n >> x;
    vector<int> m(n);
    rep(i,n) cin >> m[i];


    put(n + (x - accumulate(m.begin(), m.end(),0)) / *min_element(m.begin(), m.end()));
}