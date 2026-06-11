//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;


int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  int a[n];
  int b[n];
  string memo = s.substr(0,1);
  int acnt = 0;
  int bcnt = 0;
  if(memo == "1"){
    a[0] = 0;
    acnt++;
  }else{
    b[0] = 0;
    bcnt++;
  }
  rep(i,n){
    // printf("%s\n",s.substr(1,i).c_str() );
    if(s.substr(i,1) != memo){
      if(memo == "1"){
        b[bcnt] = i;
        bcnt++;
      }else{
        a[acnt] = i;
        acnt++;
      }
      memo = s.substr(i,1);
    }
  }


  int ans = 0;
  if(bcnt <= k){
    printf("%d\n", n);
    return 0;
  }else{
    if(s[0] == '1'){
      rep(i,bcnt-k){
        ans = max(ans,b[i+k]-a[i]);
      }
      if(s[s.size()-1] == '1'){
        ans = max(ans,n-a[bcnt-k]);
      }else{
        ans = max(ans,n-a[bcnt-k]);
      }
    }else{
      rep(i,bcnt-k-1){
        ans = max(ans,b[i+k+1]-a[i]);
      }
      ans = max(ans,a[k-1]+1);
      if(s[s.size()-1] == '1'){
        ans = max(ans,n-a[bcnt-k-1]);
      }else{
        ans = max(ans,n-a[bcnt-k-1]);
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
