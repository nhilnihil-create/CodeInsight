#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
using namespace std; typedef long long ll; const int INF=1e9;
typedef pair<int,int> P;

int keta(ll a) {int res=0; while(a>0) res+=a%10, a/=10; return res;}
int main() {
  int n; cin>>n;
  int an=1e9;
  for(int i=1;i<n;i++) {
    an = min(an, keta(i) + keta(n-i));
  } 
  cout<<an<<endl;
}