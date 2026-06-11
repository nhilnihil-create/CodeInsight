#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    int n;
    cin>>n;
    int ans=n;
    for(int i=0;i<=n;i++){
        int now=0;
        int t=i;
        while(t>0){
            now+=t%6;
            t/=6;
        }
        t=n-i;
        while(t>0){
            now+=t%9;
            t/=9;
        }
        ans=min(ans,now);
    }
    cout<<ans<<endl;
}