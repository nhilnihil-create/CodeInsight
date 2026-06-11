#include<algorithm>//sort(all(変数),greater<型名>())　で降順に
#include<bits/stdc++.h>
#include<cmath>//切り上げceil(値)
#include<deque>
#include<iomanip>//setprecision(数字)
#include<iostream>
#include<list>
#include<map>
#include<numeric> //xとyの最大公約数は__gcd(x,y),xとyの最小公倍数は(x*y)/__gcd
#include<queue>//priority_queue<型名> 変数：優先度付きキュー　最大値の探索が早い
#include<set>
#include<stack>
#include<string>
#include<vector> //*max_element(all(変数))で最大値を獲得
#define rep0(i,n)  for(ll i=0; i<n; i++)
#define rrep0(i,n) for(ll i=n-1; 0<=i; i--)
#define vll vector<ll>
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e18
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  ll k,a,b; cin >> k >> a >> b;
  if(b-a <= 2){
    cout << k+1;
  }else{
    k -= a-1;  ll biscuit = a;
    biscuit += (k/2)*(b-a) + k%2;
    cout << biscuit;
  }
}
