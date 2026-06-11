#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  int n,h,w;
  cin >> n >> h >> w;
  VI a(n),b(n);
  rep(i,n)cin >> a.at(i) >> b.at(i);
  int cnt=0;
  rep(i,n){
    if(a.at(i)>=h && b.at(i)>=w)cnt++;
  }
  cout << cnt << endl;
    
}