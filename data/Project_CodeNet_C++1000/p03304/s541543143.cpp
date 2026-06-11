#include<iostream>
#include<iomanip>
using namespace std;
using ld = long double;

int main() {
  ld N, D; long M; cin >> N >> M >> D;
  cout<<setprecision(15)
    <<(D>0 ? 2 : 1)*(N-D)/N/N*(M-1)<<endl;
}