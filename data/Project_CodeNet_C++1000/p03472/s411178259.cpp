#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int n;
  ll h;
  cin >>n >>h;
  ll count=0;
  ll a[n],b[n];
  ll am=0;//刀を振る時の最大ダメージ
  rep(i,n){
    cin >> a[i] >> b[i];
    am=max(a[i],am);
  }
  sort(b,b+n);

  for(int i=n-1;i>=0;i--){
    if(b[i]<=am)break;
    count++;
    h-=b[i];
    if(h<=0)break;
  }
  if(h>0){count+=(am+h-1)/am;}

  cout << count << endl;

}