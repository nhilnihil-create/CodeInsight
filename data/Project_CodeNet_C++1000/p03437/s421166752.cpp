#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>
using namespace std;

long long gcd(long long a, long long b){
  if(b == 0){ return a;}
  return gcd(b, a%b);
}

long long lcm(long long a, long long b) {
  long long g = gcd(a,b);
  return (a/g)*b;
}

int main(){
  long long x, y;
  cin >> x >> y;
  if(x%y==0){
    cout << -1 << endl;
    return 0;
  }
  cout << lcm(x,y) - x << endl;
  return 0;
} 
