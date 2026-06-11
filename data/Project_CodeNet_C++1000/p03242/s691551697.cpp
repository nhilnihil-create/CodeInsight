#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   string n;
   cin>>n;
   for(int i=0;i<3;i++){
       if(n[i]=='1'){n[i]='9';}
       else if(n[i]=='9'){n[i]='1';}
   }
   cout<<n<<endl;
return 0;}