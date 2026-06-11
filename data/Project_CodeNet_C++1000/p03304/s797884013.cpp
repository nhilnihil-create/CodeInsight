#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  double n,m,d;
  
  cin >> n >> m >> d;
  
  if (d==0.0) printf("%.12lf\n",(m-1)/n);
  else printf("%.12lf\n",(n-d)*2*(m-1)/(n*n));
  
  return 0;
}