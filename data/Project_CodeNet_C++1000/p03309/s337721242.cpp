//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
//using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll n; cin>>n;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
        a[i]-=i+1;
    }
    sort(all(a));
    ll mid;
    ll ans=0;
    vector<ll>b=a;
    vector<ll>c=a;
    if(n%2==1){
        mid=-1*b[n/2];
        rep(i,n){
            b[i]+=mid;
            ans+=abs(b[i]);
        }
        cout<<ans<<endl;
        return 0;
    }
    else{
        ll mid1=-1*c[n/2-1],mid2=-1*c[n/2];
        ll ans1=0,ans2=0;
        rep(i,n){
            c[i]+=mid1;
            ans1+=abs(c[i]);
        }
        c=a;
        rep(i,n){
            c[i]+=mid2;
            ans2+=abs(c[i]);
        }
        ans=min(ans1,ans2);
        cout<<ans<<endl;
    }

}









