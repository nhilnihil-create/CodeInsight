#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 

 

 
int main(){
   int n;
   cin >> n;
   VI a(n);
   rep(i,n)cin >> a.at(i);
   ll sum=0;
   rep(i,n){
      sum+=a.at(i);
   }
   int dif=100000000;
   int ans=1000;
   rep(i,n){
      int x=a.at(i)*n;
      int y=abs(sum-x);
      if(y<dif){
         dif=y;
         ans=i;
      }
   }
   cout << ans << endl;
   


} 
