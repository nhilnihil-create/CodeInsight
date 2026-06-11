#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;


signed main() {
int n;
cin>>n;
int a,b,l=0,ans=MOD;
for(int i=0;i<n;i++){
    cin>>a>>b;
    l+=a;
    if(a>b)ans=min(ans,b);
}
if(ans==MOD)cout<<0;
else cout<<l-ans;



return 0;
}
