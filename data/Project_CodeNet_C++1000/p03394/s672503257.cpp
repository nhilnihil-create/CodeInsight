#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#include<random>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

ll gcd(ll n, ll m) {
	ll tmp;
	while (m!=0) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m) {
	return abs(n) / gcd(n, m)*abs(m);//gl=xy
}
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;

void func(int n){
  set<int>st;
  st.emplace(2);st.emplace(3);
  int num=4;
  while(st.size()<n-1){
      if((num%2==0)||(num%3==0))st.emplace(num),++num;
      else ++num;
  }
  ll sum=0;
  for(auto x:st){
    sum+=x;
  }
  while(1){
    ++num;
    if(gcd(sum,num)!=1){
      if((num%2==sum%2)&&(num%3==(3-sum%3)%3)){
        st.emplace(num);
        break;
     }
    }
  }
  for(auto x:st){
    cout<<x<<" ";
  }
  cout<<endl;
}

void solve(){
  int n;
  cin>>n;
  set<int>st;
  st.emplace(2);st.emplace(3);st.emplace(5);
  if(n==3){
    cout<<2<<" "<<3<<" "<<25;
    return;
  }
  int num=4;
  while(st.size()<n-1){
      if((num%2==0)||(num%3==0)||(num%5==0))st.emplace(num),++num;
      else ++num;
  }
  ll sum=0;
  for(auto x:st){
    sum+=x;
  }
  while(1){
    ++num;
    if(gcd(sum,num)!=1){
      if((num%2==sum%2)&&(num%3==(3-sum%3)%3)&&(num%5==(5-sum%5)%5)){
        st.emplace(num);
        break;
     }
    }
    if(num>30000){
      func(n);
      return;
    }
  }
  for(auto x:st){
    cout<<x<<" ";
  }
  cout<<endl;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
