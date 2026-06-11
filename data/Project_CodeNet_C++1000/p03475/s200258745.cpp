#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll> c(n),s(n),f(n),ans(n);
    rep(i,n-1){
        cin >> c[i] >>s[i]>> f[i];
    }
    rep(i,n){
        int t = 0;
        for(int j = i; j<n-1;++j){
            if(t<s[j])t=s[j];
            else if (t%f[j]==0);
            else t +=f[j] - t%f[j];
            t+=c[j];
        }
        printf("%d\n",t);
    }
    return 0;
}