#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<ll>a(n);
    ll last=0;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        if(i==0){
            if(a[i]>0){
                cout<<-1<<endl;
                return 0;
            }
        }else{
            if(a[i]>a[i-1]+1){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    ll ans=0;
    for(int i=n-1;i>0;i--){
        if(a[i]==a[i-1]+1)ans++;
        else ans+=a[i];
    }
    cout<<ans<<endl;
}