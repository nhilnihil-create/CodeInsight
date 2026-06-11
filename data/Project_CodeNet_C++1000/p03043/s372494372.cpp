#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;

int main(){
  ll N,K;
  cin >> N >> K;
  double ans=0;
  for(ll i=0;i<N;i++){
    int nn = i+1;
    double tmp = 1.0/N;
    while(nn<K){
      nn*=2;
      tmp/=2;
    }
    ans += tmp;
  }
  printf("%.12f\n",ans);
}
