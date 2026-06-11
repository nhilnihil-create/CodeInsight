#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;


int main(){
   int N,H,W;
   cin>>N>>H>>W;
   vector<int>A(N);
   vector<int>B(N);
   int count=0;
   rep(i,N){
       cin>>A[i]>>B[i];
       if(H<=A[i]&&W<=B[i]){
           count++;
       }
   }
   cout<<count<<endl;
    return 0;
}