#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int h,w;
  cin >> h >> w;
  set<pair<int,int>> s;
  int n;
  cin >> n;
  rep(i,n){
    int x,y;
    cin >> x >> y;
    s.insert(make_pair(x,y));
  }
  int k[h];
  k[0]=1;
  rep(i,h-1){
    if(k[i]==h)k[i+1]=h;
    else{
      if(s.count(make_pair(i+2,k[i]+1))){
        k[i+1]=k[i];
      }
      else{
        k[i+1]=k[i]+1;
      }
    }
  }
  int ans=h;
  for(pair<int,int>p: s){
    int x=p.first,y=p.second;
    if(x==1)continue;
    if(k[x-2]>=y)ans=min(ans,x-1);
  }
  cout << ans << endl;
}
