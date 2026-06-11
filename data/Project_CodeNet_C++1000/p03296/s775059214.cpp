#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std; typedef long long ll; const int MINF=-1e9; typedef pair<int,int> P;

int main() {
  int n; cin>>n;
  int a[n]; for(int i=0;i<n;i++) cin>>a[i];
  int an=0;
  for(int i=1;i<n;i++) {
    if (a[i-1]==a[i]) an++, a[i]=-1;
  }
  cout<<an<<endl;
}