#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
   int n;
   cin>>n;
   vector<int> h(n+1);
   rep(i,n)cin>>h[i];
   int count=0;
   rep(i,100){
       rep(j,n){
          if(h[j]>0){
              h[j]--;
              if(h[j+1]==0)count++;
          }
       }
   }
   cout<<count<<endl;
}