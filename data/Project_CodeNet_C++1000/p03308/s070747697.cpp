#include<bits/stdc++.h>

#define ll long long
const int inf = 1e9+7;
const ll INF = 1e18+7;

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  int M = 0, m = 1e9+7;
  for(int i =0; i < n; ++i){
    int tmp;
    cin >>tmp;
    M = max(M,tmp);
    m = min(m,tmp);
  }
  cout<<M-m<<"\n";
}
