#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <map> // pair
#include <numeric> // accumulate(begin,end,初期値)

typedef long long ll;
using namespace std;

#define FALSE printf("false\n");
#define TRUE printf("true\n");
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<x<<endl;
#define rep(i,n) for(ll i = 0;i < n;++i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SUM(vec) accumulate(all(vec),0);

const ll INF = 1e9+7;

// 各桁の和
template<typename T>
T digit(T num){
  T sum = 0;
  while(num){
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

template<typename T>T gcd(T a,T b){
  if(b == 0)
    return a;
  return gcd(b,a%b);
}
template<typename T>T lcm(T a, T b){
  T g = gcd(a,b);
  return a/g*b; 
}
template<typename T>T power(T a,T b){
  T tmp = 1;
  rep(i,b){
    tmp *= a;
  }
  return tmp;
}
int main(){
  ll x,y;cin>>x>>y;
  if(x % y == 0)print(-1)
    else print(x)
  return 0;
}
