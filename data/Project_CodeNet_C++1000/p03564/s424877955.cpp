#include <bits/stdc++.h>
using namespace std;
 
int main() {int64_t n,k,a;
            a=1;
  cin>>n>>k;
for(int64_t i=0;i<n;i++)
{a=min(a*2,a+k);}  
cout<<a<<endl;
}