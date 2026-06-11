#include<bits/stdc++.h>
#define INF 2147483647
#define inf 1000000007
#define lol long long
#define in(n,s) insert(n,s) //文字列の挿入 
// s.erase(s.begin()+1) 文字列の削除
// 小文字を大文字は -32
#define SYOU(x) setprecision(x)
#define abs(x,y) (max(x,y)-min(x,y))
#define mp make_pair
#define fi first
#define se second
using namespace std;
struct Per{
  int number;
  string name;
};
lol i[111100];
bool ii[11111];
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long a,b,c,d=0,e=0,f=0,g=1,h=2,j;
  string s,w,p;
  cin >>s>>a;
  for(int n=0;n<s.size();n++){
    if(n%a==0) w.push_back(s[n]);
  }
  cout <<w<<'\n';
  return (0);
}
