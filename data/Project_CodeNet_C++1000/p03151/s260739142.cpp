//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,suma=0,sumb=0,r=0; cin>>n;
    vector<ll> a(n,0),b(n,0),ov;
    ll cnt=0;
    rep(i,n){
        cin>>a[i]; suma+=a[i];
    }
    rep(i,n){
        cin>>b[i]; sumb+=b[i];
        if(a[i]<b[i]){
            r+=b[i]-a[i]; cnt++;
        }
        else ov.push_back(a[i]-b[i]);
    }
    sort(al(ov)); reverse(al(ov));
    if(suma<sumb){
        cout<<-1<<endl;
        return 0;
    }
    ll ind=0;
    while(r>0){
        r-=ov[ind]; ind++;
    }
    cout<<cnt+ind<<endl;
}
