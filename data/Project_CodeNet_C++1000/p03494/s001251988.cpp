#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
 int N;
 cin>>N;
 vector<int>A(N);
 int ans=10000000;
 rep(i,N){
   	cin>>A[i];
     int cnt=0;
     bool a=true;
     while(a==true){
         if(A[i]%2==1||A[i]<2){
             a=false;
         }
         else{
             A[i]/=2;
             cnt++;
         }
     }
     if(cnt<ans){
         ans=cnt;
     }
 }
 cout<<ans<<endl;
}
