#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,a,b;
  cin >>n >>a >>b;
  int cnt1=0, cnt2=0, cnt3=0;
  rep(i,n){
    int p;
    cin >>p;
    if(p<=a) cnt1++;
    else if(p>=a+1 && p<=b) cnt2++;
    else if(p>=b+1) cnt3++;
  }
  cout << min(min(cnt1, cnt2), cnt3) << endl;
  return 0;
}