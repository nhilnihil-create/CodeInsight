#include <bits/stdc++.h>
using namespace std;
#define ll	    long long
#define vi      vector <ll>
#define vii     vector <pair<int,int>>
#define ii      pair<int,int>
#define loop(n)	for(int i=0;i<n;i++)
#define pb      push_back
const ll mod=1e9+7;
void fast();
ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int main()
{
    fast();
    ll n,k,res=0;
    cin>>n>>k;
    ll a[n],vis[41]={};
    loop(n){
        cin>>a[i];
        for(ll j=0;j<=40;j++){
            if((a[i]&power(2,j)))
                vis[j]++;
        }
    }
    for(ll j=40;j>=0;--j){
        if(vis[j]<(n+1)/2&&power(2,j)<=k){
            k-=power(2,j);
            res+=(n-vis[j])*power(2,j);
        }
        else
            res+=vis[j]*power(2,j);
    }
    cout<<res;
}
void fast(){
std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
/*

*/
