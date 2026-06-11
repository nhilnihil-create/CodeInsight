#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std; typedef long long ll; const int INF=1e9+7;
typedef pair<int,int> P;

int main() {
  ll a,b,c; cin>>a>>b>>c;
  ll an=b;
  an+=min(c,a+b+1);
  cout<<an<<endl;
}