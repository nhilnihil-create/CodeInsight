#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);


ll gcd(ll a, ll b){  if(b==0){  return a; }   return gcd(b , a%b); }

ll cube (ll a){
  return a*a*a ;  
}
int main() {

int n;
cin>>n;
unordered_map<string,int> umap;
int flag = 1;
string first ;
cin>>first;
umap[first]++;
REP(i,n-1){
  string s,curr;
  cin>>s;
  curr = s;
  umap[s]++;
  if(first[first.length()-1] != curr[0]){
    flag = 0;
  }
  first = curr;
}

for(auto i: umap){
  if(i.second > 1){
    flag = 0;
    break;
  }
} 

if(!flag){
  cout<<"No\n";
}
else{
  cout<<"Yes\n";
}
  
  return 0;
}
