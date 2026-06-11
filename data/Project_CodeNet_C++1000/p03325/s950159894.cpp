#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)

int main(void){
    int n;
    cin>>n;
    vector<int> A(n);
    rep(i,n) cin>>A[i];
    int ans=0;
    rep(i,n){
        int a=A[i];
        while(a%2==0){
            a/=2;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}