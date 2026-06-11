#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,sum=0,ma=0;
  rep(i,5){
    cin>>x;
    sum+=(x+9)/10*10;
    ma=max(ma,(1000-x)%10);
  }
  cout<<sum-ma<<endl;
  return 0;
}