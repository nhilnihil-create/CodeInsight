#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

using ll = long long;

int main(){
  int n;
  cin>>n;
  vector<int> a(n+2);
  ll sum = 0;
  a.at(0) = 0;
  a.at(n+1) = 0;
  rep(i,n){
    cin >> a.at(i+1);
    sum += abs(a.at(i+1)-a.at(i));
  }
  sum += abs(a.at(n));
  rep1(i,n){
    ll ans = sum;
    //a.at(i)のルートを飛ばす。
    if(a.at(i-1)<a.at(i)&&a.at(i)>a.at(i+1)){
      ans += (abs(a.at(i+1)-a.at(i-1))-(a.at(i)-a.at(i-1))-(a.at(i)-a.at(i+1)));
    }else if(a.at(i-1)>a.at(i)&&a.at(i)<a.at(i+1)){
      ans += (abs(a.at(i+1)-a.at(i-1))+(a.at(i)-a.at(i-1))+(a.at(i)-a.at(i+1)));
    }
    cout<<ans<<endl;
  }
  return 0;
}