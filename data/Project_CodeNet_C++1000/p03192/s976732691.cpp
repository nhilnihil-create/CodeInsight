#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define rep2(i,k,n) for(int i=k;i<=n;i++)
typedef long long ll;
using namespace std;
int main()
{
   string N;
   cin >> N;
   ll ans = 0;
   rep(i,0,N.length()){
     if(N[i]=='2')++ans;
   }
   cout << ans << endl;
}