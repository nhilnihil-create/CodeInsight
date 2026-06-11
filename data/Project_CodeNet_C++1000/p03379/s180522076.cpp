#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main() {
 int n; cin >> n;
 vector<ll> x(n),sortx(n),ans(n);
 rep(i,n){
   cin >> x[i];
   sortx[i]=x[i];
 }
 sort(sortx.begin(),sortx.end());
 ll left=sortx[n/2-1];
 ll right=sortx[n/2];
 double med=(double)(right+left)/2.0;


 rep(i,n){
   if(x[i]<=med)cout << right << endl;
   else cout << left <<endl;
 }

}