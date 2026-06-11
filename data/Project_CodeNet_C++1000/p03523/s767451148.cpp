#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
ll gcd(ll x, ll y){
  if(y==0) return x;
  else return gcd(y, x%y);
}
ll lcm(ll x,ll y){
  ll g=gcd(x,y);
  return x/g*y;
}
 
int main() {
  string S;
  cin >> S;
  
  bool ok = false;
  if(S == "AKIHABARA") ok =true;
  
  if(S == "KIHABARA") ok =true;
  if(S == "AKIHBARA") ok =true;
  if(S == "AKIHABRA") ok =true;
  if(S == "AKIHABAR") ok =true;
  
  if(S == "AKIHABR") ok =true;
  if(S == "AKIHBAR") ok =true;
  if(S == "KIHABAR") ok =true;
  
  if(S == "AKIHBRA") ok =true;
  if(S == "KIHABRA") ok =true;
  if(S == "KIHBARA") ok =true;
  
  if(S == "KIHBRA") ok =true;
  if(S == "KIHBAR") ok =true;
  if(S == "KIHABR") ok =true;
  if(S == "AKIHBR") ok =true;
  
  if(S == "KIHBR") ok =true;
  
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}
  

