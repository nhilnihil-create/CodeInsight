#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
   ll a[3],k;
   cin>>a[0]>>a[1]>>a[2]>>k;
   ll sum=0;
   sort(a,a+3);
   while(k--)
   {
       a[2] = 2*a[2];
       sum = a[1]+a[2]+a[0];
   }
   cout<<sum<<endl;
}
