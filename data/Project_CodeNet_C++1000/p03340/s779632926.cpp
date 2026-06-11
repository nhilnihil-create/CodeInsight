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
#define i_7 (ll)1E9+7
#define i_5 (ll)1E9+5
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

/////////////////////////////////////////////////////
bool check(ll a,ll b){
    while(a>0&&b>0){
        if((a&1)&(b&1))return false;
        a/=2;
        b/=2;
    }
    return true;
}


int main(){
    int n;cin>>n;
    int a[n];rep(i,0,n-1)cin>>a[i];
    ll ans=0;
    int s=0,t=0;//[s,t]
    ll sum=a[0];
    while(t<=n-1){
        while(t<=n-2){
            if(check(sum,a[t+1])){
                sum+=a[t+1];
                t++;
            }else break;
        }
        ans+=t-s+1;
      //  cout<<s<<" "<<ans<<endl;
        sum-=a[s];
        s++;
        if(s>t){
            t=s;
            sum+=a[t];
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
