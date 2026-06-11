#include <iostream>
#include <string>
using namespace std;
 
int findsum(int n){
  int sum = 0;
  while(n>0){
    sum += n % 10;
    n/=10;
  }
  return sum;
}

int main() {
  int N,a,b;
  cin >> N >> a >> b;
  int total = 0;
  for(int i=1;i<=N;++i){
    int sum=findsum(i);
    if(sum >= a & sum <= b){
      total += i;
    }
  }
  cout << total << endl;
}