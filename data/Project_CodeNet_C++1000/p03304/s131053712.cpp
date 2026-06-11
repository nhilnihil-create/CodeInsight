#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  cout << fixed << setprecision(10);
  long long n,m,d;cin>>n>>m>>d;
  //m-1が最大値
  //1,1+d
  //n-d,n
  long long ok = 0;
  if(d!=0)ok = (n-d)*2;
  else ok = (n-d);
  long long al = n*n;
  cout << (long double)(m-1)*ok/al << endl;
}