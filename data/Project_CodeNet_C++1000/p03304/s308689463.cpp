#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  long long n,m,d;
  double ans=0.0;
  cin >> n >> m >> d;
  for(int i=0;i<m-1;i++){
    if(d==0){
      ans+=(double)(1.000/n);
    }else{
      ans+=(double)(2.000*(n-d)/n/n);
    }
  }
  printf("%.10f\n", ans);
  return 0;
}
