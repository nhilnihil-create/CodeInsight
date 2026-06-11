//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////
queue<string> que;
bool solve(int a, int b, int c, int d){
  if(a < b || d < b)return false;
  if(c >= b)return true;
  int j = b-__gcd(b,d)+(a%__gcd(b,d));
  if(j > c)return false;
  return true;
}
signed main(){
  int t;cin>>t;
  rep(i,t){
    int a, b, c, d;cin>>a>>b>>c>>d;
    que.push((solve(a,b,c,d) ? "Yes" : "No"));
  }
  while(!que.empty()){
    cout << que.front() << endl;
    que.pop();
  }
}
