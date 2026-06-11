#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  cout << a[n-1] << " ";
  ll minv = abs(a[n-1] - a[0] -  a[0]);
  ll minidx = 0;
  rep(i,n-1){
    if(minv > abs(a[n-1] - a[i] -  a[i])){
      minv = abs(a[n-1] - a[i] -  a[i]);
      minidx = i;
    }
  }
  cout << a[minidx] << endl;

  
  return 0;
    

}
