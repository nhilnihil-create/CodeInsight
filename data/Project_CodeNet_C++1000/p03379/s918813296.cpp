#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  vector<int> x(n),s;
  rep(i,n){
    cin>>x[i];
  }
  s=x;
  sort(s.begin(),s.end());
  int left=s[s.size()/2-1],right=s[s.size()/2];
  rep(i,n){
    if(x[i]<=left) cout<<right<<endl;
    else cout<<left<<endl;
  }
}