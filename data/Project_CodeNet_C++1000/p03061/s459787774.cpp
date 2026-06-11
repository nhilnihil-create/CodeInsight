#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007 
#define mod2 998244353
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}



int main() {
   fast();
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   int tri=0;
   for(int i=0;i<n;i++){
    tri=__gcd(a[i],tri);
   }
   for(int i=0;i<n;i++){
      a[i]=a[i]/tri;
   }
   if(n==1){
    cout<<mod-7<<"\n";
    return 0;
   }
   if(n==2){
    cout<<max(a[0]*tri,a[1]*tri);
    return 0;
   }
   sort(a,a+n);
   vector<int> v;
   for(int i=1;i<=sqrt(a[0]);i++){
    if(a[0]%i==0){
      v.pb(i);
      v.pb(a[0]/i);
    }
   }
   for(int i=1;i<=sqrt(a[1]);i++){
    if(a[1]%i==0){
      v.pb(i);
      v.pb(a[1]/i);
    }
   }
   sort(v.begin(),v.end());
   for(int i=v.size()-1;i>=0;i--){
    int count=0;
      for(int j=0;j<n;j++){
          if(a[j]%v[i]==0){
            count++;
          }
      }
      if(count==n-1){
        cout<<tri*v[i]<<"\n";
        return 0;
      }
   }
   cout<<tri<<"\n";
   return 0;


}
