#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define INF 1000000007
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
//AKIHABARA
int main(){
  string s;
  cin >> s;
  map<string,bool>ok;
  rep(i,2)rep(j,2)rep(k,2)rep(l,2){
    string tmp;
    if(i)tmp += 'A';
    tmp += "KIH";
    if(j)tmp += 'A';
    tmp += "B";
    if(k)tmp += 'A';
    tmp += 'R';
    if(l)tmp += "A";
    ok[tmp] = true;
  }
  if(ok[s])cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
