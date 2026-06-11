//include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
#include <iomanip>
#include <math.h>
#include <utility>
#include <functional>
//using
using namespace std;
using vl = vector <long long>;
using vs = vector <string>;
using vc = vector <char>;
using ll= long long;
using vvl = vector<vector<ll> >;
using vd = vector <double>;
//define
//#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;
#define sortp(d) sort(d.begin(),d.end()) //1234
#define sortm(d) sort(d.rbegin(),d.rend()) //4321
//グローバル変数宣言
 ll p=0,q=0,r=0;


int main(){
   ll s;
   cin>>s;
   vl a(1000000);
   rep(i,1000000){
      if (i==0)
      {
         a[i]=s;
      }else if (a[i-1]%2==0)
      {
         a[i]=a[i-1]/2;
      }else  a[i]=a[i-1]*3+1;
      if (a[i]==4||a[i]==2||a[i]==1)
      {
         p=i+4;break;
      }
      
      
   }
   print(p)
      
}
