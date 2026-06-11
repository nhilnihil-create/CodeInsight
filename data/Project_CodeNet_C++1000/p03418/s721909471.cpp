#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int Max = 1000000;
int main(){
  	ll N, K;
    cin >> N  >> K;
    
    ll ans = 0;
    if(K==0){
      cout << N*N <<endl;
      return 0;
    }

    for(ll b=K+1;b<=N;b++){
      ll q = (N-K)/b;
      ll gap = N-q*b - K;
      ll gap2 = min(gap+1, b-K);
      ans += (q+1)*(gap2) + q*(b-K-gap2);
      //cout << ans << endl;
    }	

    cout << ans <<endl;

  	return 0;
}
