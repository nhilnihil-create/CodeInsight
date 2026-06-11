#pragma GCC optimize("Ofast")
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,long double> Pi;
typedef pair <long double,int> Pd;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
string a,b,c;
cin>>a>>b>>c;
int ans=0;
for(int i=0;i<n;i++){
   string s={};
   s+=a[i];
   s+=b[i];
   s+=c[i];
   //cout<<s<<endl;
   sort(all(s));
   s.erase(unique(all(s)),s.end());
   if(s.size()==2)ans++;
   else if(s.size()==3)ans+=2;
}
cout<<ans<<endl;
}

