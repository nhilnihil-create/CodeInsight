#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;

int main(){
   int n,k; cin>>n>>k;
   vector<int> a(n);
   rep(i,n) cin>>a[i];
   sort(a.rbegin(),a.rend());
   int cnt=0;
   rep(i,n){
      if (a[i]==a[0]) cnt++;
   }
   int ans=0;
   if((n-cnt)%(k-1)==0) ans= (n-cnt)/(k-1);
   else ans= (n-cnt)/(k-1)+1;
   cout<<ans<<endl;
   return 0;
}

   
