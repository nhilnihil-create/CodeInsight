#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define int long long
#define puts(x) cout<<x<<endl
#define inf 243000000000000001
#define minf -243000000000000001



signed main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ans[0]=0;
    ans[1]=abs(v[1]-v[0]);
    for(int i=2;i<=n-1;i++){
        int val=inf;
        for(int j=i-1;j>=max((int)0,i-k);j--){
            val=min(val,ans[j]+abs(v[j]-v[i]));
        }
        ans[i]=val;
    }
    puts(ans[n-1]);
}
  