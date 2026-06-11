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
#define i_7 1000000007
#define i_5 1000000005


ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=1000000000000;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}


/////////////////////////////////////////////////////////////////



int main(){
    string s;cin>>s;
    int a[3];memset(a,0,sizeof(a));
    int n=s.size();
    rep(i,0,n-1)a[s[i]-'a']++;
    sort(a,a+3);
    if(n==1)cout<<"YES"<<endl;
    else if(a[2]-a[0]>=2)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}