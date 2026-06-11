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
    int n;cin>>n;
    vector<int>ans;
    int count=1;
    if(n==3){
        ans.pb(2);ans.pb(5);ans.pb(63);
    }else if(n>=19999){
        int pos=1;
        while(count<=n){
            if(pos%2==0||pos%3==0){ans.pb(pos);count++;}
            pos++;
        }
    }else{
        int pos=7;
        ll sum=0;
        while(count<=n-2){
            if(pos%2==0||pos%3==0){
                ans.pb(pos);
                count++;
                sum+=pos%6;
            }
            pos++;
        }
        int k=sum%6;
        int perm[4]={2,3,4,6};
        do{
            if((k+perm[0]+perm[1])%6==0){
                ans.pb(perm[0]);ans.pb(perm[1]);
                break;
            }
        }while(next_permutation(perm,perm+4));
    }
    for(auto x:ans)cout<<x<<" ";cout<<endl;
    return 0;
}