#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main() {
 int n; cin >> n;
 ll ans=1;
 rep(i,n)ans*=3;
 int cnteven=0;
 rep(i,n){
   int a; cin >> a;
   if(a%2==0)cnteven++;
 }
 ll d=pow(2,cnteven);
 cout << ans-d <<endl; 

}
