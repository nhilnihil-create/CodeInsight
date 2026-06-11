#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;



int main(){
   int n,k; cin>>n>>k;
   vector<int> a(n);
   rep(i,n) cin>>a[i];
   sort(a.begin(),a.end());
   int cnt=0;
   rep(i,n){
       if(a[i]==a[0]) cnt++;
       else break;
   }
   int num=n-cnt;
   int ans;
   if(num%(k-cnt)==0){
       ans=num/(k-cnt);
   }
   else ans=num/(k-cnt)+1;
   cout<<ans<<endl;
   return 0;
}

   
