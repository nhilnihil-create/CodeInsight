#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
 int a,b,x;
  cin >> a >> b >> x;
  if(x<=a+b && a<=x){
  cout << "YES" << endl;
  }
  else cout << "NO" << endl;
}