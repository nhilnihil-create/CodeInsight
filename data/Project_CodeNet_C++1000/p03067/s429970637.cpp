#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main(){
   int a,b,c;
   cin>>a>>b>>c;
   if(b>a)
   swap(a,b);
   if(b<=c && c<=a)
   cout<<"Yes";
   else
   cout<<"No";
  return 0;
}
