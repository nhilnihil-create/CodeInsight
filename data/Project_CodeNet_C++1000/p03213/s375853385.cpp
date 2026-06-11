#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<55)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

void prime_div(vector<ll> &ret,ll n){
    ll x=n;
    for(ll i=2;i*i<=x;i++){
	    while(n%i==0){
  		    n/=i;
            ret.push_back(i);
	    }
    }
    if(n!=1){ 
	    ret.push_back(n);
    }

    return;
}

int main(){
    ll n;cin>>n;

    vector<ll> ret;
    for(ll i=1;i<=n;i++){
        prime_div(ret,i);
    }
    sort(ret.begin(),ret.end());
    ret.push_back(INF);

    vector<ll> pr(101,0);
    ll num=1;
    rep(i,ret.size()-1){
        if(ret[i]==ret[i+1]){
            num++;
        }else{
            if(num!=1){
                pr[ret[i]]=num;
            }
            num=1;
        }
    }

    ll n2=0,n4=0,n14=0,n24=0,n74=0;
    rep(i,pr.size()){
        if(pr[i]>=74){
            n74++;
        }
        if(pr[i]>=24){
            n24++;
        }
        if(pr[i]>=14){
            n14++;
        }
        if(pr[i]>=4){
            n4++;
        }
        if(pr[i]>=2){
            n2++;
        }
    }
    
    cout<<n74+n24*(n2-1)+n14*(n4-1)+n4*(n4-1)*(n2-2)/2<<endl;
    return 0;
}