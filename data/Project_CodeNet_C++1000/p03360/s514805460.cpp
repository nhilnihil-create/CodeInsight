#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int  k; 
    vector<int> a(3);
    rep(i,3) cin >> a[i];
    cin >> k;
    int maxn = *max_element(a.begin(),a.end());
    int n = maxn;

    rep(i,k) maxn *= 2;

    put(maxn + accumulate(a.begin(),a.end(),0) - n);
}