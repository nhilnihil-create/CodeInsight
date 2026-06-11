#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int a,b,c,k;
    vector<int> d(3);
    cin >> a >> b >> c >> k;
   if(abs(a - b) > 1e18){
   cout << "Unfair" << endl;
   return 0;
   }
   else
   {
       if(k % 2 == 0)
       cout << a - b << endl;
       if(k % 2 == 1)
       cout << -(a - b) << endl;
   }
   
}