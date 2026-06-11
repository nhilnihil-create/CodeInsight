#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;




int main(){
    
   int n;
   cin>>n;
   string s;
   cin>>s;

   vector<int> east(n+1);
   east[0]=0;
    rep(i,n){
        if(s[i]=='E') east[i+1]++;
    }
    rep(i,n){
        east[i+1] += east[i];
    }
    ll ans=1e12;
    for(ll i=1;i<=n;i++){
        ans=min(ans, i-1-east[i-1]+east[n]-east[i]);
    }
    cout<<ans<<endl;
    

    return 0;
}
