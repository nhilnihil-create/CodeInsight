#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  ll n;
  cin >> n;
  if(n == 3){
    printf("3 5 22\n");
    return 0;
  }
  for(int i = 1;(i+1)*2 <= 30000;i+=3){
    if(n <= 3)break;
    printf("%d %d ",i*2,(i+1)*2);
    n -= 2;
  }
  for(int i = 1;(i+2)*3 <= 30000;i+=4){
    if(n <= 1)break;
    printf("%d %d ",i*3,(i+2)*3);
    n -= 2;
  }
  for(int i = 1;;i++){
    if(n == 0)break;
    printf("%d ",i*6);
    n--;
  }
  printf("\n");




  return 0;
}