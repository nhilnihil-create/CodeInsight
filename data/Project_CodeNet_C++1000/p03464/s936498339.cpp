#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;
 
int main(){
   int k; cin >> k;
   vector<ll> a(k);
   rep(i,k) cin >> a[i];
   ll mn=2; ll ma=3;
   if(a[k-1]>2){
       cout << -1 << endl;
       return 0;
   }
   for(int i=k-2; i>=0; i--){
       mn=a[i]*((mn-1)/a[i]+1);
       ma=((ma/a[i])+1)*a[i]-1;
       //mn=((mn-1)/a[i]+1)*a[i];
       //ma=(ma/a[i])*a[i]+a[i]-1;
       //cout << ma << endl;
       //cout << mn << ' ' << ma << endl;
       if(mn>ma){
           cout << -1 << endl;
           return 0;
       }
   }
 
   cout << mn << ' ' << ma << endl;
return 0;
}