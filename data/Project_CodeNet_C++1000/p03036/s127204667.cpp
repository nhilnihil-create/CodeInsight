#include <bits/stdc++.h>

using namespace std;

int main() {

   long long r,d,x,res;
   cin>>r>>d>>x;
   int tests=10;
   res = x;
   while(tests--){
       res = r*res - d;
       cout<<res<<endl;
   }
    return 0;
}
