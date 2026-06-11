#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int n, tt; cin >> n >> tt;
    vector<int> c(n), t(n);
    rep(i,n) cin >> c[i] >> t[i];

    int index = -1, minc = 1e9;
    for(int i = 0; i < n; i++){
        if(c[i] <= minc && t[i] <= tt){
            minc = c[i];
            index = i;
        }
    }
    if(index < 0) put("TLE");
    else put(c[index]);
}