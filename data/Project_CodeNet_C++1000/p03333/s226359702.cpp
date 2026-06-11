#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;
typedef unsigned long long ull;



int main(){
 int n;
 cin >> n;
 vector<ll> a(n),b(n);
 rep(i,n) cin >> a[i] >> b[i];
 sort(all(a));
 reverse(all(a));
 sort(all(b));
 ll ans=a[0];
 ll h=0;
 rep(i,n*2){
   if (i%2==0){
     if (a[i/2]<=b[i/2]) break;
     ans+=a[i/2]-b[i/2];
     h=b[i/2];
   }
   else{
     if (a[i/2+1]<=b[i/2]) break;
     ans+=a[i/2+1]-b[i/2];
     h=a[i/2+1];
   }
 }
 ans+=abs(h);
 ll p=ans;
 h=0;
 ans=-b[0];
 rep(i,n*2){
   if (i%2==0){
     if (a[i/2]<=b[i/2]) break;
     ans+=a[i/2]-b[i/2];
     h=a[i/2];
   }
   else{
     if (a[i/2]<=b[i/2+1]) break;
     ans+=a[i/2]-b[i/2+1];
     h=b[i/2+1];
   }
 }
 ans+=abs(h);
 cout << max(ans,p) << endl;
}
