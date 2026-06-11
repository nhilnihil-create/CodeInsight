#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define repo(i,N) for(int i = 1; i < (N); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//#define num 1000000007
#define pi acos(-1.0)
//cout << fixed << setprecision (20);   小数点以下2０桁まで
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'0'+=16;        で大文字に
//'大文字'+=32;    で小文字に
//s[i]-'0'でchar文字→int数に;
//string s = to_string(int数);
//int n = stoi(string文字列)


int main() {
  string s;
  cin >> s;
  int n = s.size();
  
  bool ans = true;
  
  if(s[0]!='A') ans = false;
  repo(i,n) {
    if(s[i]=='A') ans = false;
  }
  
  bool ome = false;
  for (int i = 2; i<=n-2; i++) {
    if(s[i]=='C') ome = true;
  }
  if(ome==false) ans=false;
  
  int count = 0;
  rep(i,n) {
  if(s[i]=='C') count++;
  }
  if(count!=1) ans = false;

  
  rep(i,n) {
    if(s[i]!='A' && s[i]!='C' && s[i]<'a' || 'z'<s[i]) ans=false;
  }
  
  cout << (ans?"AC":"WA") << endl;

}