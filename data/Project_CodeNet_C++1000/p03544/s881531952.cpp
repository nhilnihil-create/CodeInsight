#include <bits/stdc++.h>
using namespace std;

long long n,a[100];

int main(){
   cin>>n;
   a[0]=2;
   a[1]=1;
   for(int i=2;i<=n;i++) {
    a[i]+=(a[i-1]+a[i-2]);
   }
   cout<<a[n];


    return 0;
}
