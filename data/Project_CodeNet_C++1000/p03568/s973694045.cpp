#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main()
{
   int n;cin >>n;
   int a[n];int ans=0;
   int b=1;
   for(int i=0;i<n;i++){
    cin >>a[i];
    if(a[i]%2==0)b*=2;
    else b*=1;
   }
   int k=1;
   for(int i=0;i<n;i++){
    k*=3;
   }
   ans+=k;
   ans-=b;
   cout << ans << endl;
    return 0;
}
