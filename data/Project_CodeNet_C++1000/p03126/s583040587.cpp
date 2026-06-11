//Foods Loved by Everyone

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end()
#define pb push_back
const int inf = 2147483647;

int main (){
    int n,m;cin>>n>>m;
    vector<vector<int>> a(n);
    rep(i,0,n){
        int k;cin>>k;
        rep(j,0,k){
            int c;cin>>c;
            a[i].pb(c);
        }
    }
    vector<int> t(m);
    rep(i,0,n){
        rep(j,0,a[i].size()){
            t[a[i][j]-1]++;
        }
    }
    int ans=0;
    rep(i,0,m)if(t[i]==n)ans++;
    cout << ans << endl;
    return 0;
}