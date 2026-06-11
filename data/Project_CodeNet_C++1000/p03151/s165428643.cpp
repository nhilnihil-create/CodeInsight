#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <cmath>

typedef long long ll;
using namespace std;

#define FALSE printf("false\n");
#define TRUE printf("true\n");
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<x<<endl
#define rep(i,n) for(int i = 0;i < ((int)(n));++i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SUM(vec) accumulate(all(vec),0LL)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define test(a) cout<<(#a)<<':'<<(a)<<endl

const int INF = 1e9+7;
const ll INFL = 9*1e18;

ll inline digit(ll num){int tmp = 0;while(num){tmp++;num/=10;}return tmp;}
template<typename T>inline T digitSum(T num){T sum = 0;while(num){sum+=num%10;num/=10;}return sum;} // 各桁の和
template<typename T>inline T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<typename T>inline T lcm(T a, T b){T g = gcd(a,b);return a/g*b;}
template<typename T>inline T power(T a,T b){T tmp=1;rep(i,b){tmp*=a;}return tmp;}

bool isOk(ll key,ll value){
  return key < value;
}

int binary_search(vector<ll> a,ll key){
  ll ok = a.size();
  ll ng = -1;

  while(abs(ok - ng) > 1){
    ll mid = (ok + ng) / 2;
    if(isOk(key,a[mid]))ok = mid;
    else ng = mid;
  }
  return ok;
}


int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;cin>>n;
  vector<int> a(n),b(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  ll plus = 0, minus = 0;
  ll bad = 0;
  vector<ll> points;
  rep(i,n){
    if(a[i] < b[i]){
      bad += abs(a[i] - b[i]);
    }else points.pb(a[i]-b[i]);
  }
  if(bad == 0){
    print(0);
    return 0;
  }


  int ans = -1;
  sort(all(points));reverse(all(points));
  ll tmp = 0;
  rep(i,points.size()){
    tmp += points[i];
    if(bad <= tmp){
      ans = i+1 + n - (points.size());
      break;
    }
  }
  print(ans);
  return 0;
} 
