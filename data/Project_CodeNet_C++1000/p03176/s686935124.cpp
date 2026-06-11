#include <bits/stdc++.h>
#define db(x) cout<<x<<" "
#define db1(x) cout<<x<<'\n'
#define db2(x,y) cout<<x<<" "<<y<<'\n'
#define db3(x,y,z) cout<<x<<" "<<y<<" "<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define pair(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ll  long long int
#define vi vector<ll>
#define pi pair<ll,ll>
#define vpi vector<pair<ll,ll>>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define mod 1000000007
#define MAX_N 
using namespace std;
// int dx[4] = {1,-1,0,0};
// int dy[4] = {0,0,1,-1};

class Flower{
public:
    int height;
    int beauty;

};

void solve(){

    ll n;
    cin>>n;

    vector<Flower> arr(n);

    rep(i,n){
        cin>>arr[i].height;
    }

    rep(i,n){
        cin>>arr[i].beauty;
    }    

    vector<ll>dp(n);

    dp[0]=arr[0].beauty;
    map<ll,ll> meaning;
    meaning[arr[0].height]=arr[0].beauty;

    repA(i,1,n-1){
        dp[i]=arr[i].beauty;
        auto it = meaning.lower_bound(arr[i].height+1);
        if(it!=meaning.begin()){
            it--;
            dp[i]+=it->second;
        }
        meaning[arr[i].height]=dp[i];
        it = meaning.upper_bound(arr[i].height);
        while(it!=meaning.end() && dp[i]>=it->second){
            auto temp = it;
            temp++;
            meaning.erase(it);
            it=temp;
        }
    }

    ll ans = 0;

    rep(i,n)
    ans=max(ans,dp[i]);

    db1(ans);

}


int main(){ 
int t=1;
//cin>>t;
while(t--){
 solve();
}
  return 0; 
}



