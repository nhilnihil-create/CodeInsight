#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   ll k,a,b;
   cin >> k >> a >>b;
   ll ans;
   if(a+1>=b)ans=k+1;
   else{
     if(a-1>k)ans=1+k;
     else{
       ll lst=k-a+1;
       if(lst%2==0)ans=a+(lst/2)*(b-a);
       else ans=a+(lst/2)*(b-a)+1;
     }  
   }
   cout << ans << endl;
}