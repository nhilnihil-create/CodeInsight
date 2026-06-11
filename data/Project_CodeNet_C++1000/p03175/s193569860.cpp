


#include <bits/stdc++.h>
using namespace std;
#define ll long long 
vector<int> t[100001];
ll dp[100001][2];

int mod=1e9+7;

ll ways( int root, int cons,int pr){

if(dp[root][cons]!=-1){

    return dp[root][cons];

}

ll ans=0;

    ll w1=1;

    for( int child: t[root]){

        if(child!=pr){
            w1=(w1*ways(child,0,root))%mod;
        }
    }
    ans+=w1;

    if(cons==0){

        ll w2=1;
       for( int child: t[root]){

        if(child!=pr){
            w2=(w2*ways(child,1,root))%mod;
        }

    }
    ans=(ans+w2)%mod;


    }


 return dp[root][cons]=ans;




}

int main() {
   int n;
   cin>>n;

   for(int i=0;i<n-1;i++){
       int x,y;
       cin>>x>>y;
       t[x].push_back(y);
       t[y].push_back(x);
   }

    memset(dp,-1,sizeof(dp));


   cout<<ways(1,0,-1);


}
