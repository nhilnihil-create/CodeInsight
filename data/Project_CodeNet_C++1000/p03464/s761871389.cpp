#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int k;
cin>>k;
vector<ll> a(k);
for(int i=0;i<k;i++)cin>>a[i];
ll mi=2,ma=2;
for(int i=k-1;i>=0;i--){
     if(ma/a[i]==(mi-1)/a[i]){
         cout<<-1<<endl;
         return 0;
     }
     ma=(ma/a[i]+1)*a[i]-1;
     mi=((mi+a[i]-1)/a[i])*a[i];
}
cout<<mi<<" "<<ma<<endl;
}