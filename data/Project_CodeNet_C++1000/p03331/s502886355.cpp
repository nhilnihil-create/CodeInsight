#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int ds(int d){
   if(d < 10)  return d;
   return ds(d/10) + d%10;
}

int main(){
    int n;
    cin>>n;
    int ans=1e9;
    for(int i=1; i<n; ++i){
        int x=n-i;
    ans=min(ans,ds(i)+ds(x));
    }
    cout<<ans<<endl;
}
