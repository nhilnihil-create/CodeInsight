#include <iostream>
using namespace std;

 int all(int n){
    int sum = 0;
    while(n > 0){
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  
  int count = 0;
  for(int i = 1; i <= N; i++){
    int sumsum = all(i);
    if(all(i) >= A && all(i) <= B){
      count += i;
    }
  }
  
  cout << count << endl;
}
