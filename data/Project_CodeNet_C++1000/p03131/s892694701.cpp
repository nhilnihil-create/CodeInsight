#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main()
{
   ll k,a,b;
   cin >>k >>a >>b;
   ll ans=1;
   if(k<=a-1){
    cout << ans+k<< endl;
    return 0;
   }
   else {
    if(b-a<=2){
         cout << ans+k<< endl;
        return 0;
    }
    ans=a;k-=(a-1);
        ans+=(b-a)*(k/2)+k%2;
        cout << ans << endl;
   }
    return 0;
}
