#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}

////////////////////////////////////////


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll q;cin>>q;
    while(q--){
        ll a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        ll ans=2*(a-1);
        ll p=(ll)sqrt(a*b);
        if(a<b-1){
            if(a==p){
                ans+=1;
            }else{
                ans+=1;
                ans+=2*(p-a-1);
                if(p*(p+1)<a*b)ans+=2;
                else if(p*p<a*b)ans+=1;
                if((a*b-1)/(a+2)==b-2)ans--;
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
