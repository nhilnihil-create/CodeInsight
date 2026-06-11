#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){

   int a,b,k;
   cin>>a>>b>>k;
   int c=0;
   for(int i=min(a,b);i>=1;i--){
        if(a%i==0 && b%i==0){
            c++;
        }
        if(c==k){
            cout<<i;
            break;
        }
   }


return 0;
}
