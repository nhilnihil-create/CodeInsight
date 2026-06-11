#include <bits/stdc++.h>
#define rep(i,n); for(int i = 0;i < (n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
long double pi = acos(-1);
const int INF = 1001001001;


// 最小公倍数を求める
int euqlid (int a, int b){
  int temp;
  temp = a % b;
  if(temp == 0)return b;
  return euqlid(b,temp);
}
ll conbination(ll a,ll b){
  ll u = 1;
  ll d = 1;
  while(b != 0){
    u *= a;
    d *= b;
    a--;
    b--;
  }
  return u / d;
}
int strtoint(char s){
  return (int(s-'0'));
}
int fact(int n){
  if(n == 1)return 1;
  return n * fact(n-1);
  }


int main(){
  string s;
  cin >> s;
  bool alpha[3];
  int ans = 0;
  rep(i,3)alpha[i] = false;
  rep(i,3){
    if(s[i] == 'a')alpha[0] =true;
    else if(s[i] == 'b')alpha[1] =true;
    else if(s[i] == 'c')alpha[2] = true;
  }
  rep(i,3)if(alpha[i] == true)ans++;
  cout << (ans == 3?"Yes":"No") << endl;

}
