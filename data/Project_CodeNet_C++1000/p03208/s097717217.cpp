#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    rep(i,n)    cin >> v[i];

    sort(v.begin(),v.end());

    int ans(v[k-1]-v[0]);
    for(int i=0;i<n-k+1;i++){
        ans = min(ans,v[i+k-1]-v[i]);
    }

    cout << ans << endl;

    return 0;
}