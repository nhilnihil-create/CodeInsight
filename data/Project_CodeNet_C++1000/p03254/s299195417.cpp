#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,x;
    cin>>n>>x;
    vi a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(), a.end());
    
    int ans = 0;
    rep(i,n){
        if(x<a[i])break;
        x -= a[i];
        ans++;
        if(x>0 && i==n-1)ans--;
    }
    cout << ans << endl;
    return 0;
}