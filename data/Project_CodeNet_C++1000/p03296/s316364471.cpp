#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1000000;
const int MOD = 1000000007;

signed main() {
 int n;
 cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
int k=1,ans=0;
for(int i=1;i<n;i++){
    if(a[i]!=a[i-1]){
        ans+=k/2;
        k=1;
    }else k++;
}
ans+=k/2;
cout<<ans;

return 0;
}
