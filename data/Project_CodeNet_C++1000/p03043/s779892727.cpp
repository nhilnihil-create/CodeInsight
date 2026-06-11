#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 double n,k;
 cin >> n >> k;
 double ans=0;
 for(double i=1;i<=n;i++){
  int a=0;
  int b=i;
  while(b<k){
    b*=2;
    a++;
  }
  ans+=1/pow(2,a);
 }
 ans/=n;
 cout << fixed << setprecision(12) << ans << endl;

}