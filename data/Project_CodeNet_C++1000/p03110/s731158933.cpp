#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  long double ans = 0;
  for(int i=0;i<n;i++){
    long double x;
    string u;
    cin >> x >> u;
    if(u=="JPY"){
      ans += x;
    }else if(u=="BTC"){
      ans += x*380000;
    }
  }

  printf("%.10Lf\n",ans);
}