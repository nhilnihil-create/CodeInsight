#include <bits/stdc++.h>
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
using namespace std;
int main(void){
    ll n,p;
    cin>>n>>p;
    vector<pair<ll,ll>>vec;
    ll val=sqrt(p);
    for(ll i=2;i<=val;i++){
        ll cnt=0;
        while(p%i==0){
            cnt++;
            p/=i;
        }
        if(cnt>0){
            vec.push_back(make_pair(i,cnt));
        }
    }
    if(p!=1)vec.push_back(make_pair(p,1));
    ll ans=1;
    for(int i=0;i<vec.size();i++){
        while(vec[i].second>=n){
            ans*=vec[i].first;
            vec[i].second-=n;
        }
    }
    cout<<ans<<endl;
 return 0;   
}