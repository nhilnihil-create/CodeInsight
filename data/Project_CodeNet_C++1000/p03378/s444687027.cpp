#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int n, m, x; cin >> n >> m >> x;
  vector<int> a(m);
  int cost0 = 0;
  int costN = 0;
  for(int i=0; i<m; i++){
  	cin >> a[i];
    if(a[i] < x) cost0++;
    if(x < a[i]) costN++;
  }
  cout << min(cost0, costN) << endl;
  
    return 0;
}