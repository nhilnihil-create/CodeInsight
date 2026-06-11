#include <bits/stdc++.h>

using namespace std;

#define pan(i,n) for(int i=0;i<n;i++)
#define pans(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define vi vector<ll>
#define vl vector<ll>
#define pb push_back
#define INF 1000000007
#define PI 3.141592653
#define inf 100007
#define pll pair<ll,ll>
#define pii pair<int,int>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int main(){
    ll n,res=0;
    cin>>n;
    vl v(n),psum;
    pan(i,n){
        cin>>v[i];
        if(i==0) psum.pb(v[i]);
        else psum.pb(psum[i-1]+v[i]);
    }
    sort(psum.begin(),psum.end());
    pan(i,(int)psum.size()){
        if(psum[i]==0) res++;
        int x=lower_bound(psum.begin()+i+1,psum.end(),psum[i])-psum.begin(),y=upper_bound(psum.begin()+i+1,psum.end(),psum[i])-psum.begin();
        if (psum[x]==psum[i]) res+=(y-x);
    }
    cout<<res;
}