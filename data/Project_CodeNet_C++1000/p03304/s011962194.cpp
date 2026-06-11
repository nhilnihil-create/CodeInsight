#include<iostream>
using namespace std;

int main() {
  long long int n,m,d;
  cin >> n >> m >> d;
  double res;
  if(d == 0){
    res = (double)n / (n*n) * (m - 1);
  }
  else {
    res = ((double)(n-d) * 2) / (n*n) * (m - 1);
  }
  printf("%.12f",res);
  cout << endl;
  return 0;
}
