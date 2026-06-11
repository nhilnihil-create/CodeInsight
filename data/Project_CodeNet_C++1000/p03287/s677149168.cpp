#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll m[N],s[N],cum[N];
int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
   cin>>n>>m;
   map<ll,int>mp;
   ll ans=0;
   cum[0]=0;
   ll sum=0;
   mp[0]=1;
   for(int i=0;i<n;i++){
       int c;
   cin>>c;
    cum[i]=cum[i-1]+c;
    cum[i]%=m;
    ans+=mp[cum[i]];

    mp[cum[i]]++;

   }
   cout<<ans;





    return 0;
}
