#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;



int main(){
ll N;cin >> N;
bool C = 0;
  
rep(n, 1, 3501){

  rep(h, 1, 3501){
    
      if((4*h*n - N*n - N*h) == 0)continue;

      ll w = (N*n*h)/(4*h*n - N*n - N*h);

      if((N*n*h)%(4*h*n - N*n - N*h) == 0 && 0 <= w && w <= 3500){

        cout << h << " " << n << " " << w;C = 1;break;

      }

  }
  
if(C)break;
  
}
}