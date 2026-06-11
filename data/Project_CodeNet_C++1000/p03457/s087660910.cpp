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

   vector<tuple<int,int,int>> a;
   rep(i,n){
      int t,x,y;
      cin>>t>>x>>y;
      a.emplace_back(t,x,y);
   }
   sort(a.begin(),a.end());
   int xb=0;
   int yb=0;
   int tb=0;
   bool f=true;
   rep(i,n){
      int ta=get<0>(a[i]);
      int xa=get<1>(a[i]);
      int ya=get<2>(a[i]);

      if(abs(xa-xb)+abs(ya-yb)>(ta-tb)){
         f=false;
         break;
      }
      else{
         if(((abs(xa-xb)+abs(ya-yb))%2)!=abs((ta-tb)%2)){
            f=false;
            break;
         }
      }
      tb=ta;
      xb=xa;
      yb=ya;
   }

   f? cout<<"Yes":cout<<"No";

   return 0;
}
