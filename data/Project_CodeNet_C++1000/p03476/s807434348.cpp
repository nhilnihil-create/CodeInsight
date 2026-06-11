#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
typedef long long ll;

int main(){
  vector<bool> ert(100005,1);
  ert[0] = 0;
  ert[1] = 0;
  rep(i,100005){
    if(!ert[i]) continue;
    for(int j=i+i;j<100005;j += i){
      ert[j] = 0;
    }
  }
  vector<int> sum(100005,0);
  for(int i=1;i<100005;i++){
    sum[i] = sum[i-1];
    if(i%2) sum[i] += ert[i] * ert[(i+1)/2];
  }
  int q;
  cin >> q;
  rep(i,q){
    int l,r;
    cin >> l >> r;
    cout << sum[r] - sum[l-1] << endl;
  }
}