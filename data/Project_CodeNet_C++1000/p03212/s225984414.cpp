#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  ll n;
  cin >> n;
  queue<ll> que;
  ll res = 0;
  que.push(3);
  que.push(5);
  que.push(7);
  while(!que.empty()){
    ll k = que.front();que.pop();
    if(k > n)break;
    res++;
    que.push(k*10+3);
    que.push(k*10+5);
    que.push(k*10+7);
  }
  que = queue<ll>();
  que.push(3);
  que.push(5);
  while(!que.empty()){
    ll k = que.front();que.pop();
    if(k > n)break;
    res--;
    que.push(k*10+3);
    que.push(k*10+5);
  }
  que = queue<ll>();
  que.push(3);
  que.push(7);
  while(!que.empty()){
    ll k = que.front();que.pop();
    if(k > n)break;
    res--;
    que.push(k*10+3);
    que.push(k*10+7);
  }
  que = queue<ll>();
  que.push(5);
  que.push(7);
  while(!que.empty()){
    ll k = que.front();que.pop();
    if(k > n)break;
    res--;
    que.push(k*10+5);
    que.push(k*10+7);
  }
  ll k = 3;
  while(k <= n)res++,k = k*10+3;
  k = 5;
  while(k <= n)res++,k = k*10+5;
  k = 7;
  while(k <= n)res++,k = k*10+7;
  cout << res << endl;





  return 0;
}