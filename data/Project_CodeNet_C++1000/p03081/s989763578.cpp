#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

ll n,q;
char t[200010],d[200010];
string s;

bool checkleft(ll left){
    for(ll i=0;i<q;i++){
        if(t[i]==s[left]){
            if(d[i]=='R')left++;
            else left--;
        }
        if(left<0)return true;
        if(left>n-1)return false;
    }
    return false;
}

bool checkright(ll right){
    for(ll i=0;i<q;i++){
        if(t[i]==s[right]){
            if(d[i]=='R')right++;
            else right--;
        }
        if(right>n-1)return true;
        if(right<0)return false;
    }
    return false;
}

int main(void){
    cin>>n>>q;
    cin>>s;
    for(ll i=0;i<q;i++){
        cin>>t[i]>>d[i];
    }
    ll okl=-1,ngl=n;
    while(ngl-okl>1){
        ll mid=(okl+ngl)/2;
        if(checkleft(mid))okl=mid;
        else ngl=mid;
    }
    ll ngr=-1,okr=n;
    while(okr-ngr>1){
        ll mid=(okr+ngr)/2;
        if(checkright(mid))okr=mid;
        else ngr=mid;
    }
    ll ans=n;
    ans-=(n-okr);
    ans-=okl+1;
    cout<<ans<<endl;
    return 0;
}