#include<bits/stdc++.h>
using namespace std;
int main(){
  long r,d,a; cin >> r >> d >> a;
  vector<long> x(100);
  x.at(0) = a;
  for(int i = 1; i <= 10; i++){
    x.at(i) = r * x.at(i - 1) - d;
    cout << x.at(i) << endl;
  }
}