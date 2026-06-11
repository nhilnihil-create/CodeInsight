#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main(){
    ll m,k;cin>>m>>k;
    if(pow(2,m)<=k){
        cout<<-1<<endl;
        return 0;
    }
    
    if(m==0){
        if(k==0){
            cout<<"0 0"<<endl;
        }else{
            cout<<-1<<endl;
        }
        return 0;
    }else if(m==1){
        if(k==1){
            cout<<-1<<endl;
        }else if(k==0){
            cout<<"0 0 1 1"<<endl;
        }else{
            cout<<-1<<endl;
        }
        return 0;
    }
    
    ll a_num=pow(2,m+1);
    ll a[a_num];
    ll i=0;
    ll j=0;
    while(j<pow(2,m)){
        if(j==k){
            j++;
            continue;
        }else{
            a[i]=j;
            i++;
            j++;
            continue;
        }
    }
    a[i]=k;
    i++;
    j--;
    while(j>=0){
        if(j==k){
            j--;
            continue;
        }else{
            a[i]=j;
            i++;
            j--;
            continue;
        }
    }
    a[i]=k;
    cout<<a[0];
    rep(i,1,a_num-1){
        cout<<' '<<a[i];
    }
    cout<<endl;
    
    return 0;
}

