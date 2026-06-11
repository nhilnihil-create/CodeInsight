#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 int n;
 cin >> n;
 VI a(n);
 rep(i,n)cin >> a.at(i);
 int ans=__gcd(a.at(0),a.at(1));
 for(int i=2;i<n;i++){
   ans=__gcd(ans,a.at(i));
 }
 cout << ans << endl;
}
