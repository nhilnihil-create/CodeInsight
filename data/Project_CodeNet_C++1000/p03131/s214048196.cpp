#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main(){
  int k,a,b;
  cin >> k >> a >>b;//a=1円交換レート
  ll bis=1;
  int money=0;
  rep(i,k){
    if (money>0){
      money--;
      bis+=b;
    }
    else if(bis>=a && a<b &&(b-a)>2 &&(k-i)>1){
      money++;
      bis-=a;
    }
    else {
      bis++;
    }
  }
  cout << bis <<endl;
  return 0;
}