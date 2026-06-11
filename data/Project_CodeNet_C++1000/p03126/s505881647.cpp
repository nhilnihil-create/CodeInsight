#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
vector<ll> a(55), p(55);

 
int main(){
  int n, m;
  cin >> n >> m;
  int b[m]={};
  for(int i=0; i<n; i++){
    int k;
    cin >> k;
    for(int j=0; j<k; j++){
      int a;
      cin >> a;
      a--;
      b[a]++;
    }
  }
  int ans = 0;
  for(int i=0; i<m; i++){
    if(b[i]==n) ans++;
  }
  cout << ans << endl;
  return 0;
}
