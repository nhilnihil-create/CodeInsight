#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ld long double
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> k(m);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    k[i]=make_pair(b,a);
  }
  sort(k.begin(),k.end());
  int cnt=0;
  int left=-1;
  rep(i,m){
    if(k[i].second<left)continue;
    else{
      cnt++;
      left=k[i].first;
    }
  }
  cout << cnt << endl;
}