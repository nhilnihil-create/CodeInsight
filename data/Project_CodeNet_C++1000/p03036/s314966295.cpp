#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;

int main() {
  
  int a,b,c,d,x;
  long long la,lb;
  double da,db;
  string s,ss,sss;
  
  int ans = 0;
  string anss = "";
  
  cin >> a >> b >> c;
  
  int ab [] = {0 , 1 , 3 , 1 , 2 , 1 , 2 , 1 , 1 , 2 , 1 , 2 , 1};
  int result3 = std::max({a, b, c});
//--------------------------------------------------------------------------------
ans = c;
  rep(i,0,10){
  	ans = a*ans - b;
    cout << ans << endl;
  }
  
  

}