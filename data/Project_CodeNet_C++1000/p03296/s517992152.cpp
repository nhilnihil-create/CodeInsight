#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define mod 1000000007 //10^9+7
#define INF 1000000000000 //10^12
#define P pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
int n,ans=0;
int a[150];
signed main(){
    cin>>n;
    rep(i,n)cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            ans++;
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
