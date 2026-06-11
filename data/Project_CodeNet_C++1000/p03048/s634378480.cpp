#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=n;++i)

int main() {
 vector<int> a(3);
 rep(i,2)cin >> a[i];
 int n; cin >> n;
 sort(a.begin(),a.end());
 int  d2=n/a[1], d3=n/a[2];
 long long cnt=0;
 rep(i,d2)rep(j,d3){
   int m=n-a[1]*i-a[2]*j;
   if(m%a[0]==0 && m>=0){
     cnt++;
   }
 }
 cout << cnt << endl;
}
