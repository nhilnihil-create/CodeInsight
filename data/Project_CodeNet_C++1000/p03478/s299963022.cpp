#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  long long N,A,B;
  cin >> N >> A >> B;

  long long sum=0,res=0;

  for(int i = 1; i <= N; ++i){
    int ii=i;
    while(ii != 0){
      sum += ii%10;
      ii /= 10;
    }
    if(sum >= A && sum <= B){
      res += i;
    }
    sum=0;
  }
  cout << res << endl;
}

