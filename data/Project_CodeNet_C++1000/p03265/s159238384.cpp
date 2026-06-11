#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll x_1,y_1,x_2,y_2;
  cin>>x_1>>y_1>>x_2>>y_2;
  ll b=x_1-x_2;
  ll a=y_2-y_1;
  cout<<x_2-a<<' '<<y_2-b<<' '<<x_1-a<<' '<<y_1-b<<endl;
  return 0;
}