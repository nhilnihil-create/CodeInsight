#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000


signed main()
 {
   int a,b;
   cin>>a>>b;
   int ans=0;
   rep(i,b-a){
     ans+=i;
   }
   ans-=a;
   cout<<ans;
 }
