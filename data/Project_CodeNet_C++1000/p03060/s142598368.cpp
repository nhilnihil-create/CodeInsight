
#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
   int n;cin>>n;
   vector<int> v(n),c(n);
   rep0(i,n){
       cin>>v[i];
   }
   rep0(i,n){
       cin>>c[i];
   }
   int m=0;
   rep0(i,n){
       if(v[i]>c[i]){
           m+=v[i];
           m-=c[i];
     
       }
   }
   cout<<m<<endl;
}