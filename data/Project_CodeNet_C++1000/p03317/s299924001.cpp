#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
   int n,k;
   cin>>n>>k;
   vector<int> A(n);
   rep(i,n)cin>>A[i];
   int ans=(n-k+k-2)/(k-1)+1;
   cout<<ans<<endl;
}