#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


// probability to get AC after x try;
//p(1) = 0.5^m;
//p(2) = (1-p(1))*p(1);
//p(3) = (1-p(2)-p(1))*p(1);



int main(){
  int n,m;
  cin >> n >> m;

  //pre-calc
  double p[100000];
  double sum[100000];
  p[1] = pow(0.5,m);
  sum[1] = p[1];
  for(int i = 2; i < 100000; i++){
    p[i] = (1-sum[i-1])*p[1];
    sum[i] = sum[i-1]+p[i];
  }
  //

  double temp = 0;
  int i = 1;
  double t = 1900*m + 100*(n-m);
  
  while(t*i*p[i] > 0.00000001){
    temp += t*i*p[i];
    //cout <<  i <<" "<< t*i*p[i] << endl;
    i++;
  }

  int ans = int(temp);
  cout << ans+1 << endl;

}
