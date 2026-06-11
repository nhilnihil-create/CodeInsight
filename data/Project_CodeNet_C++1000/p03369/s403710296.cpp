#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;

int main() {
  
  int a,b,c,d,x;
  double da,db;
  string s,ss,sss;
  
  int ans = 0;
  string anss = "";
  
  cin >> s;
  
  int ab [] = {0 , 1 , 3 , 1 , 2 , 1 , 2 , 1 , 1 , 2 , 1 , 2 , 1};
  int result3 = std::max({a, b, c});
//--------------------------------------------------------------------------------
  if(s[0] == 'o') ans++;
  if(s[1] == 'o') ans++;
  if(s[2] == 'o') ans++;
  //else anss = "NO";

  cout << 700 + 100*ans << endl;

}