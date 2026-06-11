#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI acos(-1)
typedef  long long ll;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}

int main(){
   int n;
   cin>>n;
   vector<int> a(5,0);
   set<string> s;

   rep(i,n){
      string c;
      cin>>c;
      if(s.find(c)!=s.end()) continue;
      s.insert(c);
      if(c[0]=='M') a[0]++;
      else if(c[0]=='A') a[1]++;
      else if(c[0]=='R') a[2]++;
      else if(c[0]=='C') a[3]++;
      else if(c[0]=='H') a[4]++;
   }
   ll ans=0;
   for(int i=0;i<5;i++){
      for(int j=i+1;j<5;j++){
         for(int k=j+1;k<5;k++){
            ans+=(ll)a[i]*(ll)a[j]*(ll)a[k];
         }
      }
   }
   cout<<ans;
   return 0;
}
