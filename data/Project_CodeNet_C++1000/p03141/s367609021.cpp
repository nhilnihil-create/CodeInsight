#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int n;

ll solve(vector<ll>a,vector<ll>b,vector<ll>c){
   sort(c.rbegin(),c.rend());
   ll sum=0,ans=0;
   rep(i,n)sum+=b[i];
   for(int i=0;i<n;i+=2){
       ans+=c[i];
   }
   return ans-sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    vector<ll>a(n),b(n),c(n);
    rep(i,n){
        cin>>a[i]>>b[i];
        c[i]=a[i]+b[i];
    }
    cout<<solve(a,b,c)<<endl;
    return 0;
}