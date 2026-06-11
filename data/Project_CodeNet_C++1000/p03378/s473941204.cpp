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
using vi = vector <int>;
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
 ll a=0,b=0,c=0,e=0,n=0,k=0;


int main(){
   ll m,x;
   cin>>n>>m>>x;
   vi A(n+1);
   rep(i,m)cin>>A[i];
   rep(i,m)if(A[i]<x)b++;else c++;
   print(min(b,c))
}
