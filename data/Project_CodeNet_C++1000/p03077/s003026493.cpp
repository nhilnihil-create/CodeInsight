#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 ll n,a,b,c,d,e;
 cin >> n >> a >> b >> c >> d >> e ;
 ll mn=min(a,b);
 mn=min(c,mn);
 mn=min(d,mn);
 mn=min(e,mn);
 ll t;
 if(n%mn==0)t=(n/mn)-1;
 else{
      t=n/mn;
 }
 cout << 5+t << endl;
}