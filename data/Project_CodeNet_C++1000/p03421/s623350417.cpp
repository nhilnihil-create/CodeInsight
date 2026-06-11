#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

lli n,a,b;
vll p;

int main(){
  cin >> n >> a >> b;
  if(a+b-1 > n){ cout << -1 << endl;return 0;}
  lli k = n-a;
  for(lli i = 1;i <= a;i++){
    p.push_back(i*b);
    for(lli j = 1;j < b && k > 0;j++,k--){
      p.push_back(i*b-j);
    }
  }
  if(p.size() != n){ cout << -1 << endl;return 0;}
  map<lli,lli> zip;
  for(lli x : p){
    zip[x] = 0;
  }
  lli i = 1;
  for(auto& x : zip){
    x.second = i;
    i++;
  }
  for(lli& x : p){
    x = zip[x];
  }
  for(lli i = 0;i < p.size()-1;i++){
    cout << p[i] << " ";
  }
  cout << p[p.size()-1] << endl;
  return 0;
}
