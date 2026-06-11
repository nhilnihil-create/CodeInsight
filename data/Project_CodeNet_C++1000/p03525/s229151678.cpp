#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> d(n);rep(i,n)cin>>d[i];
    if(n>=24){
        cout<<0<<endl;
        return 0;
    }
    int ans = 0;
    for(int i=0; i<1<<(n-1); i++){
        vector<int> D(24,0);
        D[0]++;
        D[d[0]]++;
        for(int j=0; j<n-1; j++){
            if(d[j+1]==0)D[0]++;
            else if(i>>j&1)D[d[j+1]]++;
            else D[24-d[j+1]]++;
        }
        int now = 0, M = 12;
        for(int j:D)if(j>=2)M=0;
        for(int j=1; j<24; j++){
            if(D[j]){M=min(M,j-now);now=j;}
        }
        M=min(M,24-now);
        ans=max(ans,M);
    }
    cout<<ans<<endl;
    return 0;
}