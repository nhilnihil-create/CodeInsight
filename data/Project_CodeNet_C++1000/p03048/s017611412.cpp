#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
 int r,g,b,n;
 cin >> r >> b >>g >> n;
 int x=n/r;
 int y=n/b;
 
 ll ans =0;
 rep(i,x+1){
     rep(j,y+1){
         ll m=i*r+j*b;
         if((n-m)%g==0 && n>=m)ans++;
     }
 }
 cout << ans << endl;

} 
    