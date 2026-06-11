#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> a(n);rep(i,n)cin>>a[i];
    a.push_back(-1);
    int ans = 0, p = -1, l = 0;
    for(int i=0; i<=n; i++){
        if(p==a[i]){
            l++;
        }
        else{
            p=a[i];
            ans += l/2;
            l = 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}